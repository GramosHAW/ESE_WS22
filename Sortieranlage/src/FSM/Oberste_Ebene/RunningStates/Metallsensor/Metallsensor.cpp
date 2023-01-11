/*
 * Metallsensor.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "Metallsensor.h"
#include "MetallsensorInit.h"

void Metallsensor::entry() {
	showState();
}

void Metallsensor::exit() {

}

void Metallsensor::showState() {
	cout << "  substateMetallsensor: Metallsensor" << endl;
}

void Metallsensor::initSubState() {
	subsubstateMetallsensor = new MetallsensorInit;
}

void Metallsensor::entryStartNode() {
	initSubState();
	new (subsubstateMetallsensor) MetallsensorInit;
	subsubstateMetallsensor->entry();
}

bool Metallsensor::BAND_FREI() {
	bool handled = subsubstateMetallsensor->BAND_FREI();
	return handled;
}

bool Metallsensor::MSENS_METALL() {
	bool handled = subsubstateMetallsensor->MSENS_METALL();
	return handled;
}

bool Metallsensor::MSENS_METALL_OHNE() {
	bool handled = subsubstateMetallsensor->MSENS_METALL_OHNE();
	return handled;
}
