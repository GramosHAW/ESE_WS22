/*
 * Wait.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "WaitUebergabe.h"
#include "WSUbergeben.h"


void WaitUebergabe::entry(){

	send_event_payload(PSMG_SW_BAND_STOP, 0);
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
}


void WaitUebergabe::exit(){
	send_event_payload(PSMG_SW_BAND_START, 0);
}

void WaitUebergabe::showState(){
	cout << "  subsubstateUbergabe: Wait" << endl;
}

bool WaitUebergabe::BAND_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

bool WaitUebergabe::LS_ENDE_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

