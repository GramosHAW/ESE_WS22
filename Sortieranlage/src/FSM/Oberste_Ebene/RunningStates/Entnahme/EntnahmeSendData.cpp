/*
 * EntnahmeSendData.cpp
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#include "EntnahmeSendData.h"
#include "../../../SubEnd.h"

void EntnahmeSendData::entry() {
	//TODO bandstop, getDataReady
}

void EntnahmeSendData::exit() {
	//TODO sendDataToBroker
	// send BAND_FREI, WSW_OK
}

void EntnahmeSendData::showState() {
	cout << "  subsubstateEntnahme: EntnahmeSendData" << endl;
}

bool EntnahmeSendData::LS_ENDE_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}
