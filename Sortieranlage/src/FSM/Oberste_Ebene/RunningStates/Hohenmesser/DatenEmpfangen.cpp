/*
 * DatenEmpfangen.cpp
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */
#include "../../RunningStates/Hohenmesser/DatenEmpfangen.h"

#include "../../RunningStates/Hohenmesser/HoheKalkulieren.h"

void DatenEmpfangen::entry() {
}

void DatenEmpfangen::exit() {
}

bool  DatenEmpfangen::HM_DATA(int messdata) {
	//data->mejurments[data->numberOFmejurments] = messdata;
	//data->numberOFmejurments += 1;
	return true;
}

bool DatenEmpfangen::HM_STOP() {
	exit();
	send_event(PSMG_SW_BAND_SLOW_AUS);
	new (this) HoheKalkulieren;
	entry();
	return true;
}

void DatenEmpfangen::showState() {
	cout << " subsubstateHoenmesser: DatenEmpfangen" << endl;
}
