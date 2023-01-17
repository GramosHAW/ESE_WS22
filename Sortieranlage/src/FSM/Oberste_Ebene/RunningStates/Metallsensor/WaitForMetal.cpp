/*
 * WaitForMetal.cpp
 *
 *  Created on: 13 Jan 2023
 *      Author: andre
 */

#include "WaitForMetal.h"
#include "../../../SubEnd.h"
#include "../../../contextdata.h"

void WaitForMetal::entry() {

}
void WaitForMetal::exit() {

}

void WaitForMetal::showState() {
	cout << "  subsubstateMetallsensor: WaitForMetal" << endl;
}

bool WaitForMetal::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

bool WaitForMetal::MSENS_METALL() {
#ifdef SIM_TWIN_B
	data->Q1.front()->tup = ContextData::metal;
#else
	data->Q2.front()->tup = ContextData::metal;
#endif
}
