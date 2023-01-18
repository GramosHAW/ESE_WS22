/*
 * EntnahmeInit.cpp
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#include "EntnahmeInit.h"
#include "EntnahmeSendData.h"
#include "../../../SubEnd.h"

void EntnahmeInit::entry() {
}

void EntnahmeInit::exit() {

}

void EntnahmeInit::showState() {
	cout << "  subsubstateEntnahme: EntnahmeInit" << endl;
}

bool EntnahmeInit::LS_ENDE_BLOCK() {
	exit();
	new (this) EntnahmeSendData;
	entry();
	return true;
}

bool EntnahmeInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

