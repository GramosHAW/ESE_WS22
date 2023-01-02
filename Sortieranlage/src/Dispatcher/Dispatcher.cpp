#include "Dispatcher.h"
#include "../Events.h"
#include "../HAL/Aktorik.h"
#include "../FSM/ImpulsHandler.h"

Dispatcher* Dispatcher::m_pInstance { nullptr };
std::mutex Dispatcher::mutex_;
Dispatcher *Dispatcher::GetInstance() {
	std::lock_guard<std::mutex> lock(mutex_);
	if (m_pInstance == nullptr) {
		m_pInstance = new Dispatcher();
	}
	return m_pInstance;
}
Dispatcher::Dispatcher() {
	this->isr_thread = nullptr;
	this->run_thread = true;
	this->dispatcherChannelId = ChannelCreate(0);
	if (dispatcherChannelId == -1) {
		fprintf(stderr, "Dispatcher: Error creating Dispacher Channel %d\n",
		errno);
		exit(1);
	}
	Aktorik* aktorik = Aktorik::GetInstance();
	this->connectionIdHalAktorik = ConnectAttach(0, 0, aktorik->getchid(),
	_NTO_SIDE_CHANNEL, 0);
	if (this->connectionIdHalAktorik == -1) {
		fprintf(stderr,
				"InterruptHandler: Error connecting to Dispacher channel in HAL %d\n",
				errno);
		exit(1);
	}

}

void Dispatcher::set_FSM_chid(int fsmChid) {
	this->fsmchid = fsmChid;
}

void Dispatcher::start_HAL_PulsResiver_THREAD(void) {
	printf("I am about to start Despacher\n");
	isr_thread = new thread(&Dispatcher::handelHALpuls, this);
//	isr_thread.detach();
	printf("ich bin gestarted Despacher\n");
}

int Dispatcher::getchid() {
	return dispatcherChannelId;
}

void Dispatcher::handelHALpuls() {
	_pulse msg;
	this->fsmchid = ConnectAttach(0, 0, fsmchid,
	_NTO_SIDE_CHANNEL, 0);
	while (true) {
		int rcvid = MsgReceivePulse(dispatcherChannelId, &msg, sizeof(_pulse),
		NULL);
		//std::cout << sizeof(msg);
		if (rcvid != -1) {
			//printf("by Dispatcher resived %d\n", msg.value);

			switch (msg.code) {
			//Lichtschranke///////////////////////////////////////////////////////
			case PSMG_HW_LS_START_FREI:
				printf("I am in despacher\n");
				//TODO
				break;
			case PSMG_HW_LS_START_BLOCK:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_START_BLOCK, 0);
				break;
			case PSMG_HW_LS_SORT_FREI:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_SORT_FREI, 0);
				break;
			case PSMG_HW_LS_SORT_BLOCK:
				//TODO
				printf("I am in despacher\n");
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_SORT_BLOCK, 0);
				break;
			case PSMG_HW_LS_RUTSCHE_FREI:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_RUTSCHE_BLOCK, 0);
				break;
			case PSMG_HW_LS_RUTSCHE_BLOCK:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_RUTSCHE_FREI, 0);
				break;
			case PSMG_HW_LS_ENDE_FREI:
				//TODO
				break;
			case PSMG_HW_LS_ENDE_BLOCK:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_ENDE_BLOCK, 0);
				break;
				//Taster///////////////////////////////////////////////////////////////
			case PSMG_HW_TST_START_KURZ:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_START_KURZ, 0);
				printf("Start gedrückt");
				break;
			case PSMG_HW_TST_START_LANG:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_START_LANG, 0);
				break;
			case PSMG_HW_TST_STOP_KURZ:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_STOP_KURZ, 0);
				break;
			case PSMG_HW_TST_STOP_LANG:
				//TODO
				break;
			case PSMG_HW_TST_RESET_KURZ:
				//TODO
				break;
			case PSMG_HW_TST_RESET_LANG:
				//TODO
				break;
				//Metalsensor//////////////////////////////////////////////////////////////
			case PSMG_HW_MSENS_METALL:
				//TODO
				break;
			case PSMG_HW_MSENS_KEIN_METALL:
				//TODO
				break;
				//E-Stopp////////////////////////////////////////////////////////////////////
			case PSMG_HW_E_STOPP_TRUE:
				//TODO
				break;
			case PSMG_HW_E_STOPP_FALSE:
				//TODO
				break;
				//Hohenmesser//////////////////////////////////////////////////////////////
			case PSMG_SW_HM_START:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_START, 0);
				//TODO
				break;
			case PSMG_SW_HM_STOP:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_STOP, 0);
				//TODO
				break;
			case PSMG_SW_HM_DATA:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_DATA, msg.value.sival_int);
				//TODO
				break;
				//TO AKTORIK///////////////////////////////////////////////////////////////////////
				//AMPEL////////////////////////////////////////////////////////////////////
			case PSMG_SW_AMPEL_GRUEN_BLINK:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_BLINK, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_GELB_BLINK:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GELB_BLINK, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_ROT_BLINK:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_ROT_BLINK, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_GRUEN_AUS:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_AUS, msg.value.sival_int);
				//TODO
				break;
				//BAND///////////////////////////////////////////////////////////////////////
			case PSMG_SW_BAND_START:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_START, 0);
				//TODO
				break;
			case PSMG_SW_BAND_STOP:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_STOP, 0);
				//TODO
				break;
			case PSMG_SW_BAND_SLOW_AN:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_SLOW_AN, 0);
				//TODO
				break;
			case PSMG_SW_BAND_SLOW_AUS:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_SLOW_AUS, 0);
				//TODO
				break;
				//SORT//////////////////////////////////////////////////////////////////////
			case PSMG_SE_SORT_AUSSORTIERT:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SE_SORT_AUSSORTIERT, 0);
				break;
			case PSMG_SW_SORT_DURCH:
				MsgSendPulse(connectionIdHalAktorik,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SORT_DURCH, 0);
				break;
			}
		}
	}

}

Dispatcher::~Dispatcher() {
	if (-1 == ConnectDetach(dispatcherChannelId)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
	if (-1 == ConnectDetach(connectionIdHalAktorik)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
}
