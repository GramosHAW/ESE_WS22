/*
 * Service.cpp
 *
 *  Created on: 09.12.2022
 *      Author: Admin
 */

#include "Service.h"
#include "../Ruhezustand.h"
#include "../../BaseState.h"
#include "Standby.h"

void Service::entry() {
	cout << "Service::entry() aufgerufen" << endl;

	//this->showState();
	send_event_payload(PSMG_SW_BAND_STOP,0);

	send_event_payload(PSMG_SW_AMPEL_GRUEN_BLINK, 1);
}

void Service::exit() {
	cout << "Service::exit() aufgerufen" << endl;
	send_event(PSMG_SW_AMPEL_GRUEN_AUS);
}

void Service::initSubState() {
	//substateSERV = new Standby;
}

void Service::entryStartNode() {
	//initSubState();
	cout << " ENTRY START NODE STANDBY DU HOND " << endl;
	new (substateSERV) Standby;
	//substateSERV->entry();
}

bool Service::TST_RESET_KURZ() {
	bool handled = substateSERV->TST_RESET_KURZ();
	return handled;
}

bool Service::TST_RESET_LANG() {
	bool handled = substateSERV->TST_RESET_LANG();
	return handled;
}

bool Service::TST_STOP_KURZ(){
	bool handled = substateSERV->TST_STOP_KURZ();

		if (substateSERV->isSubEndState()) {
			exit();
			new (this) Ruhezustand;
			entry();
			entryStartNode();
			handled = true;

	}
	return handled;
}

bool Service::TST_START_KURZ(){
	bool handled = substateSERV->TST_START_KURZ();
//	if (!handled) {
//		exit();
//		new (this) Kalibrierung;
//		entry();
//		entryStartNode();
//		handled = true;
//}
	return handled;

}



bool Service::TST_START_LANG() {
	bool handled = substateSERV->TST_START_LANG();
	return handled;
}


bool Service::LS_ENDE_BLOCK() {
	bool handled = substateSERV->LS_ENDE_BLOCK();
	return handled;
}

bool Service::HM_START() {
	//TODO
	return false;
}

bool Service::LS_START_BLOCK() {
	bool handled = substateSERV->LS_START_BLOCK();
	return handled;
}

bool Service::LS_SORT_BLOCK() {
	bool handled = substateSERV->LS_SORT_BLOCK();
	return handled;
}

bool Service::LS_RUTSCHE_BLOCK() {
	bool handled = substateSERV->LS_RUTSCHE_BLOCK();
	return handled;
}

//bool Service::LS_START_BLOCK_SA2() {
//	bool handled = substateSERV->LS_START_BLOCK_SA2();
//	return handled;
//}


void Service::showState(){
	cout << " SubstateSA: Service" << endl;
}

