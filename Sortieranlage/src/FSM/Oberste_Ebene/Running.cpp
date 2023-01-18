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
#include "RunningStates/Aussortieren/Ausortieren.h"
#include "RunningStates/Rutsche/Rutsche.h"
#include "RunningStates/Metallsensor/Metallsensor.h"
#include "RunningStates/Ubergabe/Ubergabe.h"
#include "RunningStates/Entnahme/Entnahme.h"


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
	//substateNeuesWerckstuck->entry();
	substateNeuesWerckstuck->setData(data);
	substateNeuesWerckstuck->entryStartNode();

	substateHoenmesser = new Hohenmesser();
	//substateHoenmesser->entry();
	substateHoenmesser->setData(data);
	substateHoenmesser->entryStartNode();

	substateAussortieren = new Ausortieren();
	//substateAussortieren->entry();
	substateAussortieren->setData(data);
	substateAussortieren->entryStartNode();

	substateRutsche = new Rutsche();
	//substateRutsche->entry();
	substateRutsche->setData(data);
	substateRutsche->entryStartNode();

	substateMetallsensor = new Metallsensor();
	//substateMetallsensor->entry();
	substateMetallsensor->setData(data);
	substateMetallsensor->entryStartNode();
#ifdef SIM_TWIN_B
	substateEntnahme = new Entnahme();
	substateEntnahme->setData(data);
	substateEntnahme->entryStartNode();
#else
	substateUbergabe = new Ubergabe();
	substateUbergabe->entry();
	substateUbergabe->setData(data);
	substateUbergabe->entryStartNode();
#endif
}

bool Running::BAND_FREI() {
	bool handled = substateNeuesWerckstuck->BAND_FREI();
	handled = substateHoenmesser->BAND_FREI();
	handled = substateAussortieren->BAND_FREI();
	handled = substateMetallsensor->BAND_FREI();
	handled = substateRutsche->BAND_FREI();
#ifndef SIM_TWIN_B
	handled = substateUbergabe->BAND_FREI();
	cout << substateNeuesWerckstuck->isSubEndState() << substateHoenmesser->isSubEndState()
		<< substateAussortieren->isSubEndState()
		<< substateMetallsensor->isSubEndState()
		<< substateRutsche->isSubEndState()
		<< substateUbergabe->isSubEndState() << endl;
	if (substateNeuesWerckstuck->isSubEndState()
			&& substateHoenmesser->isSubEndState()
			&& substateAussortieren->isSubEndState()
			&& substateMetallsensor->isSubEndState()
			&& substateRutsche->isSubEndState()
			&& substateUbergabe->isSubEndState()) {
		exit();
		printf("zu Idle \n");
		new (this) BIdle;
		entry();
		handled = true;
	}
#else
	handled = substateEntnahme->BAND_FREI();
	if(substateNeuesWerckstuck->isSubEndState()
			&&substateHoenmesser->isSubEndState()
			&&substateAussortieren->isSubEndState()
			&&substateMetallsensor->isSubEndState()
			&&substateRutsche->isSubEndState()
			&&substateEntnahme->isSubEndState()) {
		exit();
		new (this) BIdle;
		entry();
	}
#endif

	return handled;
}
/*
 exit();
 new (this) BIdle;
 entry();
 return true;
 */

bool Running::LS_ENDE_BLOCK() {
	//TODO Sa1 oder Sa2
#ifndef SIM_TWIN_B
	bool handled = substateUbergabe->LS_ENDE_BLOCK();
#else
	bool handled = substateEntnahme->LS_ENDE_BLOCK();
#endif
	return handled;
}

bool Running::LS_RUTSCHE_BLOCK() {
	bool handled = substateRutsche->LS_RUTSCHE_BLOCK();
	return handled;
}

bool Running::BAND_FREI_SA2() {
	bool handled = substateUbergabe->BAND_FREI_SA2();
	return handled;
}

bool Running::LS_START_BLOCK_SA2() {
	bool handled = substateUbergabe->LS_START_BLOCK_SA2();
	return handled;
}

bool Running::LS_SORT_BLOCK() {
	bool handled = substateAussortieren->LS_SORT_BLOCK();
	return handled;
}
#ifdef SIM_TWIN_B
bool Running::LS_ENDE_FREI() {
	bool handled = substateEntnahme->LS_ENDE_FREI();
	return handled;
}
#endif

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
	substateNeuesWerckstuck->showState();
	substateHoenmesser->showState();
	substateAussortieren->showState();
	substateRutsche->showState();
	substateMetallsensor->showState();
#ifdef SIM_TWIN_B
	substateEntnahme->showState();
#else
	substateUbergabe->showState();
#endif
}

bool Running::LS_START_BLOCK() {
	bool handled = substateNeuesWerckstuck->LS_START_BLOCK();
	return handled;
}

//Hoenmesser
bool Running::HM_START() {
	bool handled = substateHoenmesser->HM_START();
	return handled;
}

bool Running::HM_STOP() {
	bool handled = substateHoenmesser->HM_STOP();
	return handled;
}

bool Running::HM_DATA(int data) {
	bool handled = substateHoenmesser->HM_DATA(data);
	return handled;
}

//Metalsensor
bool Running::MSENS_METALL() {
	bool handled = substateMetallsensor->MSENS_METALL();
	return handled;
}
/*
 bool Running::MSENS_METALL_OHNE() {
 bool handled = substateMetallsensor->MSENS_METALL_OHNE();
 return handled;
 }
 */
bool Running::ELMNT_DURCH() {
	bool handled = substateAussortieren->ELMNT_DURCH();
	return handled;
}
bool Running::LS_RUTSCHE_FREI() {
	bool handled = substateAussortieren->LS_RUTSCHE_FREI();
	return handled;
}

bool Running::LS_SORT_FREI() {
	bool handled = substateAussortieren->LS_SORT_FREI();
	return handled;
}

bool Running::ELMNT_AUSSORT() {
	bool handled = substateAussortieren->ELMNT_AUSSORT();
	return handled;
}
/*
 bool Running::RUTSCHE_VOLL_SA1() {
 bool handled = substateRutsche->RUTSCHE_VOLL_SA1();
 return handled;
 }
 */
bool Running::LS_ENDE_FREI_SA2() {
	bool handled = substateUbergabe->LS_ENDE_BLOCK_SA2();
	return handled;
}
