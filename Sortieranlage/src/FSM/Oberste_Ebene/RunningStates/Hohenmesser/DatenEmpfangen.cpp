/*
 * DatenEmpfangen.cpp
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */
#include "../../RunningStates/Hohenmesser/DatenEmpfangen.h"

#include "../../RunningStates/Hohenmesser/HoheKalkulieren.h"

void DatenEmpfangen::entry() {
	send_event(PSMG_SW_BAND_SLOW_AN);
}
void DatenEmpfangen::exit() {
	send_event(PSMG_SW_BAND_SLOW_AUS);
}

bool DatenEmpfangen::HM_STOP() {
	exit();
	new (this) HoheKalkulieren;
	entry();
	return true;
}

void DatenEmpfangen::showState() {
	cout << "  subsubstateHoenmesser: DatenEmpfangen" << endl;
}
