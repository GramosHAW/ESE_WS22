/*
 * EntnahmeSendData.cpp
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#include "EntnahmeSendData.h"
#include "../../../SubEnd.h"

void EntnahmeSendData::entry() {

	showState();
	send_event(PSMG_SW_BAND_STOP);

	//TODO bandstop, getDataReady
}

void EntnahmeSendData::exit() {
//	data->createJSON(data->Q1.front()->id, data->Q1.front()->tup, data->Q1.front()->heightSA1mean,
//				data->Q1.front()->heightSA2);
	data->Q1.pop();
	send_event(PSMG_SW_BAND_FREI);
	send_event(PSMG_SW_BAND_FREI_SA2);
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
