#include "InterruptHandler.h"
#include <thread>
#include "../Tools/PulseChannel.h"
#include "../Events.h"

#include <iostream>
#include <memory>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctime>
#include <chrono>
#include <queue>
#include <cstdio>

//Machine
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/netmgr.h>
#include <sys/siginfo.h>
#include <sys/dispatch.h>
#include <sys/types.h>
#include "../Dispatcher/Dispatcher.h"

time_t timer1;
time_t timer2;
struct tm y2k = { 0 };
int seconds;

InterruptHandler* InterruptHandler::m_pInstance { nullptr };
std::mutex InterruptHandler::mutex_;
InterruptHandler *InterruptHandler::GetInstance() {
	std::lock_guard<std::mutex> lock(mutex_);
	if (m_pInstance == nullptr) {
		m_pInstance = new InterruptHandler();
	}
	return m_pInstance;
}
InterruptHandler::InterruptHandler() {

	this->gpio_port = (std::shared_ptr<GPIO>) new GPIO(
			mmap_device_io(0x1000, (uint64_t) 0x44E07000));
	this->my_pulse_code = _PULSE_CODE_MINAVAIL + 1;
	this->interrupt_id = -1;
	this->isr_thread = nullptr;
	this->run_thread = true;
	this->channel = new PulseChannel();

	this->clientChannelId = ConnectAttach(0, 0, channel->getChannelId(),
	_NTO_SIDE_CHANNEL, 0);
	if (clientChannelId == -1) {
		fprintf(stderr,
				"InterruptHandler: Error connecting to IRQ channel in HAL %d\n",
				errno);
		exit(1);
	}
}

void InterruptHandler::start_ISR_THREAD(void) {
	//printf("I am about to start\n");
	isr_thread = new thread(&InterruptHandler::init_and_start, this);
	isr_thread->detach();
	//printf("ich bin gestarted\n");
}

/*
 void InterruptHandler::terminate_ISR_THREAD(void){
 this->run_thread = false;
 join_ISR_THREAD();
 }

 void InterruptHandler::join_ISR_THREAD(void){
 isr_thread->join();
 cout<<"thread terminated with success"<<endl;
 }
 */
void InterruptHandler::init_and_start(void) {
	pulseChannel_init();
	interrupt_init();
	wait_for_event();
}

void InterruptHandler::pulseChannel_init(void) {
	// Setup Event that defines pulse message
	this->my_pulse_code = _PULSE_CODE_MINAVAIL + 1;
	//_PULSE_CODE_MINAVAIL-_PULSE_CODE_MAXAVAIL
	SIGEV_PULSE_INIT(&event, clientChannelId, SIGEV_PULSE_PRIO_INHERIT,
			my_pulse_code, 0);
	//SIGEV_PULSE_INIT(&event,dispatcherChannelId,SIGEV_PULSE_PRIO_INHERIT,my_pulse_code, 0);
	this->interrupt_id = InterruptAttachEvent(GPIOINT0B, &event,
	_NTO_INTR_FLAGS_TRK_MSK);
}

void InterruptHandler::interrupt_init(void) {
	uint32_t festo_input_pins = (LS_START | LS_HEIGHT | LS_HEIGHT_OK | LS_SWITCH
			| METALL_DETECTED | SWITCH | LS_RUTSCHE | LS_END | START_BUTTON
			| STOP_BUTTON | RESET_BUTTON | E_STOP_BUTTON);

	//out32((uintptr_t) (gpio0_base + GPIO_SYSCONFIG),(0x3<<1));//smart idle
	gpio_port->SysConfig(6);
	gpio_port->EnableIRQ_1(festo_input_pins);
	gpio_port->EnableRISINGDETECT(festo_input_pins);
	gpio_port->EnableFALLINGDETECT(festo_input_pins);
	gpio_port->LowlevelDetect(0);
	gpio_port->HighlevelDetect(0);
	gpio_port->EnableDEBOUNCING(festo_input_pins);
	gpio_port->SetDEBOUNCINGTIME(255);
}

void InterruptHandler::chek_if_ruche_blocked(void) {
	sleep(1);
	if (ruche_thread) {
		MsgSendPulse(connectionIdDispacher,
		SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_SA1_RUTSCHE_VOLL, 0);
	}
}

void InterruptHandler::wait_for_event(void) {

	struct _pulse pulse;
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	this->connectionIdDispacher = ConnectAttach(0, 0, dispatcher->getchid(),
	_NTO_SIDE_CHANNEL, 0); //TODO hir muss der chanel mit der metode getchid() from Dispacher ersezt
	if (connectionIdDispacher == -1) {
		fprintf(stderr,
				"InterruptHandler: Error connecting to Dispacher channel in HAL %d\n",
				errno);
		exit(1);
	}

	while (run_thread) {
		pulse = channel->Msg_ReceivePulse();
		if (pulse.code != my_pulse_code) {
			fprintf(stderr, "Unexpected Pulse code %d\n", pulse.code);
			exit(-1);
		}

		// in der folgenden Bedingung muss GPIOINT0B durch get_activeIRQNUMBER() erzetzt werden
		// die simulation unterstützt nicht INTC Register
		if (GPIOINT0B == GPIOINT0B) // Check Interrupt Source
		{
			uint32_t triggered_events = gpio_port->GetIRQSTATUS_1();
			uint32_t data_in = gpio_port->ReadDataIn();
			gpio_port->ClearIRQ_1(triggered_events);
			// UNMASK THE IRQ
			if (-1 == InterruptUnmask(GPIOINT0B, interrupt_id)) {
				fprintf(stderr, "errno = %s", strerror(errno));
			}
			switch (triggered_events) {
			case LS_START:
				if (data_in & LS_START) {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_START_FREI, 0);
				} else {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_START_BLOCK, 0);
				}
				break;
			case LS_HEIGHT:
				//NICHT VORHANDEN
				if (data_in & LS_HEIGHT) {
					//printf("interupt LB_HEIGHT recived\n");
					//MsgSendPulse(ConnectionIdDispacher,SIGEV_PULSE_PRIO_INHERIT,INTERRUPT_PULSE,PULSE_HW_LS_HOEHE_FREI);
				} else {
					//printf("interupt LB_HEIGHT not recived\n");
					//MsgSendPulse(ConnectionIdDispacher,SIGEV_PULSE_PRIO_INHERIT,INTERRUPT_PULSE,PULSE_HW_LS_HOEHE_BLOCKIERT);
				}
				break;
			case LS_HEIGHT_OK:
				//Fileicht braucht man das nicht
				/*
				 if (data_in & LS_HEIGHT_OK) {
				 MsgSendPulse(connectionIdDispacher,
				 SIGEV_PULSE_PRIO_INHERIT, INTERRUPT_PULSE,
				 PSMG_SW_HM_START);
				 } else {
				 MsgSendPulse(connectionIdDispacher,
				 SIGEV_PULSE_PRIO_INHERIT, INTERRUPT_PULSE,
				 PSMG_SW_HM_STOP);
				 }
				 */
				break;
			case LS_SWITCH:
				if (data_in & LS_SWITCH) {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_SORT_FREI, 0);
				} else {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_SORT_BLOCK, 0);
				}
				break;
			case LS_RUTSCHE:
				if (data_in & LS_RUTSCHE) {
					ruche_thread = false;
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_RUTSCHE_FREI, 0);
				} else {
					//TODO WTF
					ruche_thread = true;
					thread chekIFblocked(
							&InterruptHandler::chek_if_ruche_blocked,this);
					chekIFblocked.detach();
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_RUTSCHE_BLOCK, 0);
				}
				break;
			case LS_END:
				if (data_in & LS_END) {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_ENDE_FREI, 0);
				} else {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_LS_ENDE_BLOCK, 0);
				}
				break;
			case METALL_DETECTED:
				if (data_in & METALL_DETECTED) {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_MSENS_METALL, 0);
				} else {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_MSENS_KEIN_METALL, 0);
				}
				break;
			case START_BUTTON:
				if (data_in & START_BUTTON) {
					seconds = 0;
					timer1 = 0;
					timer2 = 0;
					timer1 = time(NULL);
				} else {
					timer2 = time(NULL);
					seconds = timer2 - timer1;
					cout << "SEKUNDEN: " << seconds << endl;
					if (seconds < 3) {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_TST_START_KURZ, 0);
						cout << "START SHORT PRESSED" << endl;
					} else {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_TST_START_LANG, 0);
						cout << "START LONG PRESSED" << endl;
					}
				}
				break;
			case STOP_BUTTON:
				if (!(data_in & STOP_BUTTON)) {
					seconds = 0;
					timer1 = 0;
					timer2 = 0;
					timer1 = time(NULL);
				} else {
					timer2 = time(NULL);
					seconds = timer2 - timer1;
					cout << "SEKUNDEN: " << seconds << endl;
					if (seconds < 3) {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_TST_STOP_KURZ, 0);
						cout << "STOP SHORT PRESSED" << endl;
					} else {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_TST_STOP_LANG, 0);
						cout << "STOP LONG PRESSED" << endl;
					}
				}
				break;
			case RESET_BUTTON:
				if (data_in & RESET_BUTTON) {
					seconds = 0;
					timer1 = 0;
					timer2 = 0;
					timer1 = time(NULL);
				} else {
					timer2 = time(NULL);
					seconds = timer2 - timer1;
					cout << "SEKUNDEN: " << seconds << endl;
					if (seconds < 3) {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_TST_RESET_KURZ, 0);
						cout << "RESET SHORT PRESSED" << endl;
					} else {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_TST_RESET_LANG, 0);
						cout << "RESET LONG PRESSED" << endl;
					}
				}
				break;
			case E_STOP_BUTTON:
				if (data_in & E_STOP_BUTTON) {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_E_STOPP_FALSE, 0);
				} else {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_HW_E_STOPP_TRUE, 0);
				}
				break;
			default:
				break;

			}
		} else {
			fprintf(stderr, "Unexcepted interrupt source\n");
			exit(-1);
		}
	}
}
/*
 uint32_t InterruptHandler::get_activeIRQNUMBER(void){

 return in32((uint32_t)(INTC_BASE_ADRESS + INTC_SIR_IRQ));
 }
 */

InterruptHandler::~InterruptHandler() {

	gpio_port->EnableIRQ_1(0);
	gpio_port->EnableRISINGDETECT(0);
	gpio_port->EnableFALLINGDETECT(0);
	gpio_port->EnableDEBOUNCING(0);
	gpio_port->SetDEBOUNCINGTIME(0);

	if (-1 == InterruptDetach(interrupt_id)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}

	if (-1 == ConnectDetach(clientChannelId)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}

	if (-1 == ConnectDetach(connectionIdDispacher)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}

	delete channel;
	delete isr_thread;
}

