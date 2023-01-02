#include "ImpulsHandler.h"
#include "../Events.h"

ImpulsHandler::ImpulsHandler() {
	this->isr_thread = nullptr;
	this->run_thread = true;

	fsmChannelId = ChannelCreate(0);
	if (fsmChannelId == -1) {
		fprintf(stderr, "ImpulsHandeler: Error creating FSM Channel %d\n",
		errno);
		exit(1);
	}

	Dispatcher* dispatcher = Dispatcher::GetInstance();
	this->dispatcherChanel = ConnectAttach(0, 0, dispatcher->getchid(),
	_NTO_SIDE_CHANNEL, 0);
	if (this->dispatcherChanel == -1) {
		fprintf(stderr,
				"InterruptHandler: Error connecting to Dispacher channel in HAL %d\n",
				errno);
		exit(1);
	}

}

void ImpulsHandler::start_FSM_PulsResiver_THREAD(void) {
	printf("I am about to start\n");
	this->isr_thread = new thread(&ImpulsHandler::handelFSMpuls, this);
	this->isr_thread->detach();
	printf("ich bin gestarted\n");
}

int ImpulsHandler::getchid() {
	return fsmChannelId;
}

void ImpulsHandler::handelFSMpuls() {

	int mejurmentNumber = 0;
	_pulse msg;
	this->dispatcherChanel = ConnectAttach(0, 0,
			Dispatcher::GetInstance()->getchid(), _NTO_SIDE_CHANNEL, 0);
	while (run_thread) {
		int rcvid = MsgReceivePulse(fsmChannelId, &msg, sizeof(_pulse),
		NULL);
		//std::cout << sizeof(msg);

		if (rcvid != -1) {
			//printf("by Dispatcher resived %d\n", msg.value);

			switch (msg.code) {
			//Lichtschranke
			case PSMG_HW_LS_START_FREI:
				//TODO
				break;
			case PSMG_HW_LS_START_BLOCK:
				//TODO
				printf("hi aus FSM");

				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_START, 0);
				/*
				 MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				 PSMG_SW_AMPEL_GRUEN_BLINK, 1);
				 MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				 PSMG_SW_AMPEL_GELB_BLINK, 2);
				 MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				 PSMG_SW_AMPEL_ROT_BLINK, 3)
				 */
				 break;

			case PSMG_HW_LS_SORT_FREI:
				//TODO
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SE_SORT_AUSSORTIERT, 0);
				break;
			case PSMG_HW_LS_SORT_BLOCK:
				//TODO
				if (werkstucktup == flach) {

				} else {
					MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
					PSMG_SW_SORT_DURCH, 0);
				}
				break;
			case PSMG_HW_LS_RUTSCHE_FREI:
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_STOP, 0);
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_AUS, 0);
				//TODO
				break;
			case PSMG_HW_LS_RUTSCHE_BLOCK:

				//TODO
				break;
			case PSMG_HW_LS_ENDE_FREI:
				//TODO
				break;
			case PSMG_HW_LS_ENDE_BLOCK:
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_STOP, 0);
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_AUS, 0);
				//TODO
				break;
				//Taster
			case PSMG_HW_TST_START_KURZ:
				//TODO
				break;
			case PSMG_HW_TST_START_LANG:
				//TODO
				break;
			case PSMG_HW_TST_STOP_KURZ:
				//TODO
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
				//Metalsensor
			case PSMG_HW_MSENS_METALL:
				//TODO
				break;
			case PSMG_HW_MSENS_KEIN_METALL:
				//TODO
				break;
				//E-Stopp
			case PSMG_HW_E_STOPP_TRUE:
				//TODO
				break;
			case PSMG_HW_E_STOPP_FALSE:
				//TODO
				break;
				//Hohenmesser
			case PSMG_SW_HM_START:
				printf("HM start \n");
				mejurmentNumber = 0;
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_SLOW_AN, 0);
				//TODO
				break;
			case PSMG_SW_HM_STOP:
				printf("HM stop %d\n", mejurmentNumber);
				MsgSendPulse(dispatcherChanel, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_SLOW_AUS, 0);
				calculateHigt();
				//TODO
				break;
			case PSMG_SW_HM_DATA:
				if (mejurmentNumber < 200) {
					mejurments[mejurmentNumber] = msg.value.sival_int;
				}
				mejurmentNumber++;
				printf("messung %d nr:%d\n", msg.value.sival_int,mejurmentNumber);
				//TODO
				break;

			}
		}
	}

}

void ImpulsHandler::calculateHigt() {
	int mittelwert_ausen = 0;
	int mittelwert_mittel = 0;
	for (int i = 0; i < 40; i++) {
		mittelwert_ausen += mejurments[i];
	}
	mittelwert_ausen = mittelwert_ausen / 40;
	printf("mittelwert_ausen = %d \n", mittelwert_ausen);
	for (int i = 60; i < 120; i++) {
		mittelwert_mittel += mejurments[i];
	}
	mittelwert_mittel = mittelwert_mittel / 60;
	printf("mittelwert_mittel = %d \n", mittelwert_mittel);

	if (mittelwert_ausen > 2100 && mittelwert_ausen < 2400) {
		if (mittelwert_mittel > 2900 && mittelwert_mittel < 3250) {
			printf("mit Loch \n");
			werkstucktup = loch;
		} else if (mittelwert_mittel > 2100 && mittelwert_mittel < 2300) {
			printf("Hoh \n");
			werkstucktup = hoch;
		} else {
			printf("Undifined \n");
			werkstucktup = undefined;
		}
	} else if (mittelwert_ausen > 2400 && mittelwert_ausen < 2599) {
		if (mittelwert_mittel > 2400 && mittelwert_mittel < 2599) {
			printf("Flach \n");
			werkstucktup = flach;
		} else {
			printf("Undifined \n");
			werkstucktup = undefined;
		}
	}

}

ImpulsHandler::~ImpulsHandler() {
	if (-1 == ConnectDetach(fsmChannelId)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
	if (-1 == ConnectDetach(dispatcherChanel)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
}
