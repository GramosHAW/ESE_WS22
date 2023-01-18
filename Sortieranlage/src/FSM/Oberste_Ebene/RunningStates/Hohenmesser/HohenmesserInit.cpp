/*
 * HohenmesserInit.cpp
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */
#include "../../RunningStates/Hohenmesser/HohenmesserInit.h"
#include "../../../SubEnd.h"
#include "../../RunningStates/Hohenmesser/DatenEmpfangen.h"

void HohenmesserInit::entry() {
}
void HohenmesserInit::exit() {

}

bool HohenmesserInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

bool HohenmesserInit::HM_START() {
	exit();
	send_event(PSMG_SW_BAND_SLOW_AN);
	new (this) DatenEmpfangen;
	entry();
	return true;
}

void HohenmesserInit::showState() {
	cout << " subsubstateHoenmesser: HohenmesserInit" << endl;
}

