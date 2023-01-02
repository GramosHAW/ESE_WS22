/*
 * Running.cpp
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */

#include "Running.h"
#include "BIdle.h"

#include "Betrieb.h"
#include "Ruhezustand.h"
#include "RunningStates/NeuesWerkstuck/NeuesWerkstuck.h"
#include "RunningStates/Hohenmesser/Hohenmesser.h"

void Running::entry() {
	// MSG_SEND_PULSE (BAND_START)
	cout << " Running ENTRY | BAND START | GRUEN AN " << endl;
	send_event_payload(PSMG_SW_BAND_START, 0);
	send_event_payload(PSMG_SW_AMPEL_GRUEN_AN, 0);
	initSubState();
}

void Running::exit() {
	cout << " Running EXIT | BAND STOP " << endl;
	send_event_payload(PSMG_SW_BAND_STOP, 0);
	send_event_payload(PSMG_SW_AMPEL_GRUEN_AUS, 0);
	// MSG_SEND_PULSE (BAND_STOP)
}

void Running::initSubState() {
	substateNeuesWerckstuck = new NeuesWerkstuck;
	substateNeuesWerckstuck->entryStartNode();

	substateHoenmesser = new Hohenmesser();
	substateHoenmesser->entryStartNode();

	//substateAussortieren = new Ausortieren();
	//substateAussortieren->entryStartNode();

	//substateRutsche = new Rutsche();
	//substateRutsche->entryStartNode();

	//substateMetallsensor = new Metallsensor();
	//substateMetallsensor->entryStartNode();

	//substateUbergabe = new Ubergabe();
	//substateUbergabe->entryStartNode();
}

bool Running::BAND_FREI() {
	bool handled = substateNeuesWerckstuck->BAND_FREI();
	if (!handled) {
		return handled;
	}
	handled = substateHoenmesser->BAND_FREI();
	if (!handled) {
		return handled;
	}
	handled = substateAussortieren->BAND_FREI();
	if (!handled) {
		return handled;
	}
	return handled;
}
/*
 exit();
 new (this) BIdle;
 entry();
 return true;
 */

bool Running::LS_ENDE_BLOCK() {
	exit();
	new (this) BIdle;
	entry();
	return true;
}

bool Running::LS_RUTSCHE_BLOCK() {
	exit();
	new (this) BIdle;
	entry();
	return true;
}

bool Running::LS_SORT_BLOCK() {
//	exit();
//	new(this) BIdle;
//	entry();
	return true;
}

bool Running::TST_STOP_KURZ() {
//	bool handled = substateBZ->TST_STOP_KURZ();
//	if (substateBZ->isSubEndState()) {
//		exit();
//		new (this) Ruhezustand;
//		entry();
//		handled = true;
//	}
//	return handled;
	return true;
}

void Running::showState() {
	cout << "  SubstateBZ: Running" << endl;
}

bool Running::LS_START_BLOCK() {
	bool handled = substateNeuesWerckstuck->LS_START_BLOCK();
	return handled;
}

bool Running::HM_START() {
	bool handled = substateHoenmesser->HM_START();
	return handled;
}

bool Running::HM_STOP() {
	bool handled = substateHoenmesser->HM_START();
	return handled;
}

bool Running::ELMNT_DURCH() {
	bool handled = substateAussortieren->ELMNT_DURCH();
	return handled;
}
bool Running::RUTSCHE_FREI() {
	bool handled = substateAussortieren->RUTSCHE_FREI();
	return handled;
}

bool Running::LS_SORT_FREI() {
	bool handled = substateAussortieren->LS_SORT_FREI();
	return handled;
}
