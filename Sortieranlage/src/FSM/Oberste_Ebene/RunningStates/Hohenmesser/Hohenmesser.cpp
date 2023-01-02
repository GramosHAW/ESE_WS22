/*
 * Hohenmesser.cpp
 *
 *  Created on: 08.12.2022
 *      Author: The Hive
 */
#include "../../RunningStates/Hohenmesser/Hohenmesser.h"

#include "../../RunningStates/Hohenmesser/HohenmesserInit.h"

void Hohenmesser::initSubState(){
	subsubstateHoenmesser = new HohenmesserInit;
}

void Hohenmesser::entryStartNode() {
	initSubState();
	new (subsubstateHoenmesser) HohenmesserInit;
	subsubstateHoenmesser->entry();
}

void Hohenmesser::entry() {
	showState();
}

void Hohenmesser::exit() {

}

bool Hohenmesser::BAND_FREI() {
	bool handled = subsubstateHoenmesser->BAND_FREI();
	return handled;
}

bool Hohenmesser::HM_START() {
	bool handled = subsubstateHoenmesser->HM_START();
	return handled;
}

bool Hohenmesser::HM_STOP() {
	bool handled = subsubstateHoenmesser->HM_STOP();
	return handled;
}

void Hohenmesser::showState(){
	cout << "  substateHoenmesser: Hohenmesser" << endl;
}
