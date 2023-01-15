/**
 * AdcDemo.cpp
 *
 *  Created on: 15.11.2021
 *      Author: Bjoern Dittmann
 *
 * Demonstriert den Zugriff auf den simulierten ADC im ESE Praktikum.
 * Dieses Beispiel nutzt eine eigene ISR (InterruptAttach), es ist aber auch
 * möglich die selbe Funktionalität mit InterruptAttachEvent zu realisieren.
 */

#include "SimulatedADC.h"



SimulatedADC::SimulatedADC() {
	/* ### Setup ### */
	ThreadCtl(_NTO_TCTL_IO, 0);	//Request IO privileges for process.

	// Request interrupt and IO abilities.
	int procmgr_status = procmgr_ability(0,
	PROCMGR_ADN_ROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_INTERRUPT,
	PROCMGR_ADN_NONROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_INTERRUPT,
	PROCMGR_ADN_ROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_IO,
	PROCMGR_ADN_NONROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_IO,
	PROCMGR_AID_EOL);
	if (procmgr_status != EOK) {
		perror("Requested abilities failed or denied!");
		exit(EXIT_FAILURE);
	}

	InterruptEnable();			//Enables interrupts.

	adcBaseAddr = mmap_device_io(ADC_LENGTH, ADC_BASE); //Setup global ADC base address.

	/* ### Create channel ### */
	chanID = ChannelCreate(0); //Create channel to receive interrupt pulse messages.
	if (chanID < 0) {
		perror("Could not create a channel!\n");
	}

	conID = ConnectAttach(0, 0, chanID, _NTO_SIDE_CHANNEL, 0); //Connect to channel.
	if (conID < 0) {
		perror("Could not connect to channel!");
	}

	/* ### Setup interrupt ### */
	SIGEV_PULSE_INIT(&event, conID, SIGEV_PULSE_PRIO_INHERIT,
			PULSE_ADC_SAMLING_DONE, 0);

	/* Attach ISR  */
	interruptID = InterruptAttach(INTER_ADC, this->adcISR, this,
			sizeof(SimulatedADC), 0);
	if (interruptID == -1) {
		perror("InterruptAttach failed!");
		exit(EXIT_FAILURE);
	}

	/* ### Waiting for demo. ###
	 if(DEMO){
	 printf("Demo time for %d minutes...\n", DEMO_DURATION);
	 this_thread::sleep_for(chrono::minutes(DEMO_DURATION));	//main thread sleep.
	 printf("Stopping in...\n");
	 printf("3\n");
	 this_thread::sleep_for(chrono::seconds(1));
	 printf("2\n");
	 this_thread::sleep_for(chrono::seconds(1));
	 printf("1\n");
	 this_thread::sleep_for(chrono::seconds(1));
	 printf("NOW!\n");
	 } else {
	 while(true){
	 this_thread::sleep_for(chrono::hours(999999));
	 }
	 }*/

}

SimulatedADC::~SimulatedADC() {
	/* ### Cleaning up ### */

	// Detach interrupts.
	adc_clear_interrupt();
	adc_disable_interrupt();
	int intr_detach_status = InterruptDetach(interruptID);
	if (intr_detach_status != EOK) {
		perror("Detaching interrupt failed!");
		exit(EXIT_FAILURE);
	}

	// Stop receiving thread.
	MsgSendPulse(conID, -1, PULSE_STOP_THREAD, 0); //using prio of calling thread.
	receivingThread.join();

	// Close channel
	int detach_status = ConnectDetach(conID);
	if (detach_status != EOK) {
		perror("Detaching channel failed!");
		exit(EXIT_FAILURE);
	}

	int destroy_status = ChannelDestroy(chanID);
	if (destroy_status != EOK) {
		perror("Destroying channel failed!");
		exit(EXIT_FAILURE);
	}

}

void SimulatedADC::startthread() {

	thread receivingThread(&SimulatedADC::receivingRoutine, this);
	receivingThread.detach();

	/* ### Start sampling ### */
	adc_clear_interrupt();		//clear interrupt (just in case)
	adc_enable_interrupt();		//enable interrupt
	adc_ctrl_start_sample();	//start sampling
}

const struct sigevent* SimulatedADC::adcISR(void* arg, int id) {
	SimulatedADC* simADC = (SimulatedADC*) arg;

	uint32_t value = simADC->adc_read_sample_data();

	simADC->adc_clear_interrupt();
	InterruptUnmask(INTER_ADC, simADC->interruptID);

	simADC->getevent()->sigev_value.sival_int = value;
	return simADC->getevent();
}

sigevent* SimulatedADC::getevent() {
	return &event;
}

void SimulatedADC::receivingRoutine() {

	//Chanel to dipascher
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	int connectionIdDispacher = ConnectAttach(0, 0, dispatcher->getchid(),
	_NTO_SIDE_CHANNEL, 0);

	ThreadCtl(_NTO_TCTL_IO, 0);	//Request IO privileges for this thread.

	_pulse msg;
	receivingRunning = true;
	bool mejurStarted = false;

	printf("Message thread started.\n");
	int mejurmentNumber = 0;

	while (receivingRunning) {
		int recvid = MsgReceivePulse(chanID, &msg, sizeof(_pulse), nullptr);

		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.

			//Stop thread while it blocks.
			if (msg.code == PULSE_STOP_THREAD) {
				printf("Thread kill code received!\n");
				receivingRunning = false;
				continue;
			}

			//ADC interrupt value.
			if (msg.code == PULSE_ADC_SAMLING_DONE) {
				//printf("Value from adc with value %d!\n", msg.value);

				if (msg.value.sival_int < 3640) {

					if (!mejurStarted) {
						MsgSendPulse(connectionIdDispacher,
						SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_HM_START, 0);
						mejurStarted = true;
					}
					mejurmentNumber++;
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_HM_DATA,
							msg.value.sival_int);
				} else if (mejurStarted) {
					mejurStarted = false;
					mejurmentNumber = 0;
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_HM_STOP, 0);
				}

				adc_ctrl_start_sample();	//Start next sampling.
			}

			// Do not ignore OS pulses!
		}
	}

	printf("Message thread stops...\n");
}

void SimulatedADC::adc_enable_interrupt(void) {
	out32((uintptr_t) adcBaseAddr + ADC_IRQ_ENABLE_SET, ADC_IRQ_PIN_MASK);
}

void SimulatedADC::adc_disable_interrupt(void) {
	out32((uintptr_t) adcBaseAddr + ADC_IRQ_ENABLE_CLR, ADC_IRQ_PIN_MASK);
}

void SimulatedADC::adc_clear_interrupt(void) {
	out32((uintptr_t) adcBaseAddr + ADC_IRQ_STATUS, ADC_IRQ_PIN_MASK);
}

void SimulatedADC::adc_ctrl_start_sample(void) {
	out32((uintptr_t) adcBaseAddr + ADC_CTRL, 0x1);
}

uint32_t SimulatedADC::adc_read_sample_data(void) {
	return in32((uintptr_t) adcBaseAddr + ADC_DATA);
}
