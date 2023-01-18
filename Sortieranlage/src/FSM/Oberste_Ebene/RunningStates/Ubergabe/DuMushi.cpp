/*
 * DuMushi.cpp
 *
 *  Created on: 18.01.2023
 *      Author: 2nerd
 */

#include "DuMushi.h"
#include "WSUbergeben.h"

void DuMushi::entry(){
	send_event_payload(PSMG_SW_BAND_STOP, 0);
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
}

void DuMushi::exit(){

}

bool DuMushi::BAND_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

bool DuMushi::LS_ENDE_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

void DuMushi::showState(){
	cout << "  subsubstateUbergabe: DuMushi" << endl;
}
