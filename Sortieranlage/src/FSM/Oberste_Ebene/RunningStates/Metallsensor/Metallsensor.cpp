/*
 * Metallsensor.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "Metallsensor.h"
#include "WaitForMetal.h"
#include "../../../SubEnd.h"

void Metallsensor::entry() {
}

void Metallsensor::exit() {

}

void Metallsensor::showState() {
	cout << "  substateMetallsensor: Metallsensor" << endl;
	subsubstateMetallsensor->showState();
}

void Metallsensor::initSubState() {
	subsubstateMetallsensor = new WaitForMetal;
	subsubstateMetallsensor->setData(data);
}

void Metallsensor::entryStartNode() {
	initSubState();
	new (subsubstateMetallsensor) WaitForMetal;
	subsubstateMetallsensor->entry();
}

bool Metallsensor::BAND_FREI() {
	bool handled = subsubstateMetallsensor->BAND_FREI();
	if(subsubstateMetallsensor->isSubEndState()){
		exit();
		new (this) SubEnd;
		entry();
		return true;
	}
	return handled;
}

bool Metallsensor::MSENS_METALL() {
	bool handled = subsubstateMetallsensor->MSENS_METALL();
	return handled;
}
