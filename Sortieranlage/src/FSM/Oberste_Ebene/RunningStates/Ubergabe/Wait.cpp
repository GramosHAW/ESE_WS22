/*
 * Wait.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "Wait.h"
#include "WSUbergeben.h"

void Wait::entry(){
	showState();
	send_event_payload(PSMG_SW_BAND_STOP, 0);
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
}


void Wait::exit(){
	send_event_payload(PSMG_SW_BAND_START, 0);
}

void Wait::showState(){
	cout << "  subsubstateUbergabe: Wait" << endl;
}

bool Wait::BAND_FREI_SA2(){
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

bool Wait::LS_ENDE_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

