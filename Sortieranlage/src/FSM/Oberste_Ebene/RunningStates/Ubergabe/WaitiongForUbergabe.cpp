/*
 * DuMushi.cpp
 *
 *  Created on: 18.01.2023
 *      Author: 2nerd
 */

#include "WaitiongForUbergabe.h"

#include "WSUbergeben.h"

void WaitiongForUbergabe::entry(){
	send_event_payload(PSMG_SW_BAND_STOP, 0);
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
}

void WaitiongForUbergabe::exit(){

}

bool WaitiongForUbergabe::BAND_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

bool WaitiongForUbergabe::LS_ENDE_FREI_SA2(){
	send_event_payload(PSMG_SW_BAND_STATUS, 0);
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}

void WaitiongForUbergabe::showState(){
	cout << "  subsubstateUbergabe: WaitiongForUbergabe" << endl;
}
