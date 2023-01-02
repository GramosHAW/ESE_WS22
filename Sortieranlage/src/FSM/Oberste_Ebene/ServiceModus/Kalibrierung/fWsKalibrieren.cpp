/*
 * fWsKalibrieren.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "fWsKalibrieren.h"
#include "WsKalibrieren.h"

void fWsKalibrieren::entry(){
	this->showState();
}

void fWsKalibrieren::exit(){

}

bool fWsKalibrieren::TST_START_KURZ() {
	exit();
	new (this) WsKalibrieren;
	entry();
	return true;
}

void fWsKalibrieren::showState() {
	cout << " >> >> <SubSubState> fWsKalibrieren " << endl;
}





