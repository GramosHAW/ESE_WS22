/*
 * WsKalibrieren.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "WsKalibrieren.h"
#include "../Zeiten/NormalDurch.h"


void WsKalibrieren::entry() {
	this->showState();
}

void WsKalibrieren::exit() {

}

bool WsKalibrieren::TST_START_KURZ() {
	exit();
	new (this) NormalDurch;
	entry();
	return true;
}

void WsKalibrieren::showState() {
	cout << " >> >> <SubSubState> WsKalibrieren " << endl;
}

