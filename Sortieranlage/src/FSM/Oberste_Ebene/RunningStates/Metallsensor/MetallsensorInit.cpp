/*
 * MetallsensorInit.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "MetallsensorInit.h"
#include "MetallMessen.h"
#include "../../../SubEnd.h"

void MetallsensorInit::entry() {
	showState();
}

void MetallsensorInit::exit() {

}

void MetallsensorInit::showState() {
	cout << "  subsubstateMetallsensor: MetallsensorInit" << endl;
}

bool MetallsensorInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

bool MetallsensorInit::MSENS_METALL() {
	exit();
	new (this) MetallMessen;
	entry();
	return true;
}

