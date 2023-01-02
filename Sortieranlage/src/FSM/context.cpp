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

Context::Context(Actions *shared_action) : action(shared_action) {
	dispatcher_thread = nullptr;
	channelID = ChannelCreate(0);



	state = new SA1();
	state->initSubState();
	state->entry();
	state->showState();
	//state->setData(&data);
	//state->setAction(shared_action);

}

Context::Context(){
	this->dispatcher_thread = nullptr;


	channelID = ChannelCreate(0);
	if (channelID == -1) {
			fprintf(stderr, "FSM: Error creating FSM Channel %d\n",
			errno);
			exit(1);
		}
	action = nullptr;
	state = new SA1();
	state->initSubState();
	state->entry();
	state->entryStartNode();
	state->showState();
	//state->setData(&data);
	//state->setAction(shared_action);

	state->TST_START_LANG();
	state->showState();
	state->TST_START_KURZ();
	state->TST_START_KURZ();
	state->TST_START_KURZ();
	state->TST_START_KURZ();
	state->TST_START_KURZ();
	state->TST_RESET_KURZ();
	state->showState();
	state->HM_START();
	//state->showState();
	//state->TST_START_KURZ();
}

Context::~Context() {
	delete dispatcher_thread;
	delete state;
}
int Context::getChannelID() {
	return channelID;
}

void Context::start_FSM_PulsResiver_THREAD(void) {
//	cout << "starting FSM..." << endl;
	this->dispatcher_thread = new thread(&Context::awaitEvent, this);
	this->dispatcher_thread->detach();
//	cout << ">> FSM launched!" << endl;
}

void Context::awaitEvent() {

	_pulse msg;

	while(1){
		//printf("Hallo\n");
		int rcvid = MsgReceivePulse(channelID, &msg, sizeof(_pulse), NULL);
		//printf("Pulse: %d\n", msg.code);
		if(rcvid != -1) {
			switch(msg.code) {
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
			case PSMG_HW_LS_START_FREI:
				state->LS_START_FREI();
				state->showState();
				break;
			case PSMG_HW_LS_START_BLOCK:
				state->LS_START_BLOCK();
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
			case PSMG_SW_BAND_FREI:
				state->BAND_FREI();
				state->showState();
				break;
			case PSMG_HW_E_STOPP_TRUE:
				state->ESTOPP_TRUE_SA1();
				state->showState();
				break;
			case PSMG_HW_E_STOPP_FALSE:
				state->ESTOPP_FALSE_SA1();
				state->showState();
				break;
			case PSMG_SW_BAND_STOP:
				state->BAND_STOP();
				state->showState();
				break;
//			case PSMG_SW_BAND_START:
//				state->BAND_START();
//				state->showState();
//				break;
			case PSMG_HW_TST_RESET_KURZ:
				state->TST_RESET_KURZ();
				state->showState();
				break;
			case PSMG_HW_TST_RESET_LANG:
				state->TST_RESET_LANG();
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
			case PSMG_SW_READDATA_TRUE:
				state->READDATA_TRUE();
				state->showState();
				break;
			case PSMG_SW_HM_START:
				state->HM_START();
				state->showState();
				break;
			}
		}
	}
}

