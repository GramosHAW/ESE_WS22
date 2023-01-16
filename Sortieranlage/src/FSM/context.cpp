/*
 * context.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "context.h"
#include "Oberste_Ebene/SA1.h"
#include "Oberste_Ebene/Ruhezustand.h"
#include "actions.h"
#include "../HAL/InterruptHandler.h"
#include "../Events.h"
#include "WSW/WSWaechter.h"

Context::Context(Actions *shared_action) :
		action(shared_action) {
	dispatcher_thread = nullptr;
	channelID = ChannelCreate(0);

	state = new SA1();
	state->initSubState();
	state->entry();
	state->showState();

	this->newWSW();

	this->printarray();
	//state->setData(&data);
	//state->setAction(shared_action);

}

Context::Context() {
	this->dispatcher_thread = nullptr;

	channelID = ChannelCreate(0);
	if (channelID == -1) {
		fprintf(stderr, "FSM: Error creating FSM Channel %d\n",
		errno);
		exit(1);
	}
	action = nullptr;
	state = new SA1();
	state->setData(&data);

	state->initSubState();
	state->entry();
	state->entryStartNode();
	state->showState();

//	this->initarray();
//	this->newWSW();
//	this->newWSW();
//	this->newWSW();
	//state->setAction(shared_action);

//////// ZUM TESTEN DER FSM OHNE ANLAGE
//	state->FEHLER_TRUE();
//	state->showState();
//	state->TST_RESET_KURZ();
//	state->showState();
//	state->FEHLER_BEHOBEN();
//	state->showState();

}

Context::~Context() {
	delete dispatcher_thread;
	delete state;
}
int Context::getChannelID() {
	return channelID;
}

void Context::initarray() {
	for (int i = 0; i < 10; i++) {
		WSWarray[i] = nullptr;
	}
}

void Context::newWSW() {
	BaseState *WSW = new WSWaechter;
	printf("New Waechter\n");
	for (int i = 0; i < 10; i++) {
		if (WSWarray[i] == nullptr) {
			printarray();
			printf("New Waechter put\n");
			WSWarray[i] = WSW;
			printarray();
			break;
		}
	}
}

void Context::printarray() {
	for (int i = 0; i < 10; i++) {
		printf("Content: %d \n", *WSWarray[i]);
	}
	printf("\n");
}

void Context::start_FSM_PulsResiver_THREAD(void) {
	printf("I am about to start FSM\n");
	this->dispatcher_thread = new thread(&Context::awaitEvent, this);
	this->dispatcher_thread->detach();
	printf("ich bin gestarted FSM\n");

}

void Context::awaitEvent() {

	_pulse msg;

	while (1) {
		//printf("Hallo\n");
		int rcvid = MsgReceivePulse(channelID, &msg, sizeof(_pulse), NULL);
		//printf("Pulse: %d\n", msg.code);
		if (rcvid != -1) {
			switch (msg.code) {
			//TASTEN////////////////////////////////////////////////////////
			case PSMG_HW_TST_START_KURZ:
				state->TST_START_KURZ();
				state->showState();
				break;
			case PSMG_HW_TST_START_LANG:
				state->TST_START_LANG();
				state->showState();
				break;
			case PSMG_HW_TST_STOP_KURZ:
				state->TST_STOP_KURZ();
				state->showState();
				break;
			case PSMG_HW_TST_STOP_LANG:
				state->TST_STOP_LANG();
				state->showState();
				break;
			case PSMG_HW_TST_RESET_KURZ:
				state->TST_RESET_KURZ();
				state->showState();
				break;
			case PSMG_HW_TST_RESET_LANG:
				state->TST_RESET_LANG();
				state->showState();
				break;
				//LICHTSCHREKE//////////////////////////////////////////////////
			case PSMG_HW_LS_START_FREI:
				state->LS_START_FREI();
				state->showState();
				break;
			case PSMG_HW_LS_START_BLOCK:
				state->LS_START_BLOCK();
				state->showState();
				break;
			case PSMG_HW_LS_START_BLOCK_SA2:
				state->LS_START_BLOCK_SA2();
				state->showState();
				break;
			case PSMG_HW_LS_SORT_FREI:
				state->LS_SORT_FREI();
				state->showState();
				break;
			case PSMG_HW_LS_SORT_BLOCK:
				state->LS_SORT_BLOCK();
				state->showState();
				break;
			case PSMG_HW_LS_RUTSCHE_BLOCK:
				state->LS_RUTSCHE_BLOCK();
				state->showState();
				break;
			case PSMG_HW_LS_RUTSCHE_FREI:
				state->LS_RUTSCHE_FREI();
				state->showState();
				break;
			case PSMG_HW_LS_ENDE_FREI:
				state->LS_ENDE_FREI();
				state->showState();
				break;
			case PSMG_HW_LS_ENDE_BLOCK:
				state->LS_ENDE_BLOCK();
				state->showState();
				break;
				//ESTOP//////////////////////////////////////////////////////////
			case PSMG_HW_E_STOPP_TRUE_SA1:
				state->ESTOPP_TRUE_SA1();
				state->showState();
				break;
			case PSMG_HW_E_STOPP_TRUE_SA2:
				state->ESTOPP_TRUE_SA2();
				state->showState();
				break;
			case PSMG_HW_E_STOPP_FALSE_SA1:
				state->ESTOPP_FALSE_SA1();
				state->showState();
				break;
			case PSMG_HW_E_STOPP_FALSE_SA2:
				state->ESTOPP_FALSE_SA2();
				state->showState();
				break;
			case PSMG_ESTOPP_OK_SA1:
				state->ESTOPP_OK_SA1();
				state->showState();
				break;
			case PSMG_ESTOPP_OK_SA2:
				state->ESTOPP_OK_SA2();
				state->showState();
				break;
			case PSMG_SW_ESTOPP_QUIT:
				state->ESTOPP_QUIT();
				state->showState();
				break;
				//Sofwere//////////////////////////////////////////////////////
			case PSMG_SW_BAND_FREI:
				state->BAND_FREI();
				state->showState();
				break;
			case PSMG_SW_BAND_FREI_SA2:
				state->BAND_FREI_SA2();
				state->showState();
				break;
			case PSMG_SW_BETRIEB:
				state->BETRIEB();
				state->showState();
				break;
			case PSMG_SW_RUHE:
				state->RUHE();
				state->showState();
				break;
			case PSMG_SW_SERVICE:
				state->SERVICE();
				state->showState();
				break;
			case PSMG_SW_BAND_STOP:
				state->BAND_STOP();
				state->showState();
				break;
			case PSMG_SW_READDATA_TRUE:
				state->READDATA_TRUE();
				state->showState();
				break;
			//Hoenmesser////////////////////////////////////////////////////////
			case PSMG_SW_HM_START:
				//cout << " HM -starting reding  mesurment" << endl;
				state->HM_START();
				break;
			case PSMG_SW_HM_STOP:
				//cout << " HM -stoping reding  mesurment" << endl;
				state->HM_STOP();
				break;
			case PSMG_SW_HM_DATA:
				//cout << " HM -Messung wert:" << msg.value.sival_int << endl;
				state->HM_DATA(msg.value.sival_int);
				//TODO
				break;
			//DEFOULT/////////////////////////////////////////////////////
			default:
				cout << "FSM sais: SAY WAAAAAAAAT?????????????" << endl;
				cout << "PMSG bekommen: " + msg.code  << endl;
			}
		}
	}
}

