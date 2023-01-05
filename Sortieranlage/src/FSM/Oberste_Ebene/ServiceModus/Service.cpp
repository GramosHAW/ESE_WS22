/*
 * Service.cpp
 *
 *  Created on: 09.12.2022
 *      Author: Admin
 */

#include "Service.h"
#include "../Ruhezustand.h"
#include "../../BaseState.h"

void Service::entry() {
	cout << "Service::entry() aufgerufen" << endl;
	send_event_payload(PSMG_SW_AMPEL_GRUEN_BLINK, 1);
}

void Service::exit() {
	cout << "Service::exit() aufgerufen" << endl;
	send_event(PSMG_SW_AMPEL_GRUEN_AUS);
}

bool Service::TST_STOP_KURZ(){
	exit();
	new(this) Ruhezustand;
	entry();
	return true;
}

void Service::showState(){
	cout << " SubstateSA: Service" << endl;
}

