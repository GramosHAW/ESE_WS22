/*
 * Respond.cpp
 *
 *  Created on: 03.01.2023
 *      Author: 2nerd
 */

#include "Respond.h"
#include "Running.h"

void Respond::entry(){
	send_event_payload(PSMG_SW_BAND_FREI_SA2, 0);
	send_event_payload(PSMG_SW_BAND_START, 0);
}

bool Respond::LS_START_BLOCK(){
	exit();
	new(this) Running;
	entry();
	return true;
}

void Respond::showState(){
	cout << "  SubstateBZ: Respond" << endl;
}
