/*
 * Hohenmesser.cpp
 *
 *  Created on: 08.12.2022
 *      Author: The Hive
 */
#include "../../RunningStates/Hohenmesser/Hohenmesser.h"
#include "../../RunningStates/Hohenmesser/HohenmesserInit.h"
#include "../../../SubEnd.h"

void Hohenmesser::initSubState() {
	subsubstateHoenmesser = new HohenmesserInit;
	subsubstateHoenmesser->setData(data);
}

void Hohenmesser::entryStartNode() {
	initSubState();
	new (subsubstateHoenmesser) HohenmesserInit;
	subsubstateHoenmesser->entry();
}

void Hohenmesser::entry() {
}

void Hohenmesser::exit() {

}

bool Hohenmesser::BAND_FREI() {
	bool handled = subsubstateHoenmesser->BAND_FREI();
	if(subsubstateHoenmesser->isSubEndState()){
		exit();
		new (this) SubEnd;
		entry();
		return true;
	}
	return handled;
}

bool Hohenmesser::HM_START() {
	bool handled = subsubstateHoenmesser->HM_START();
	return handled;
}

bool Hohenmesser::HM_DATA(int data) {
	bool handled = subsubstateHoenmesser->HM_DATA(data);
	return handled;
}

bool Hohenmesser::HM_STOP() {
	bool handled = subsubstateHoenmesser->HM_STOP();
	return handled;
}

void Hohenmesser::showState() {
	cout << "substateHoenmesser: Hohenmesser" << endl;
	subsubstateHoenmesser->showState();
}
