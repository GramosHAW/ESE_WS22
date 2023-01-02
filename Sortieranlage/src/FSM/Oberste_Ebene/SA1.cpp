/*
 * SA1.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "SA1.h"
#include "Ruhezustand.h"

void SA1::entryStartNode() {
	new (substateSA) Ruhezustand;
	substateSA->entry();
}

bool SA1::TST_START_KURZ() {
	bool handled = substateSA->TST_START_KURZ();
	return handled;
}

bool SA1::TST_START_LANG() {
	bool handled = substateSA->TST_START_LANG();
	return handled;
}

bool SA1::TST_STOP_KURZ() {
	bool handled = substateSA->TST_STOP_KURZ();
	return handled;
}

bool SA1::LS_START_BLOCK(){
	bool handled = substateSA->LS_START_BLOCK();
	return handled;
}

bool SA1::BAND_FREI(){
	bool handled = substateSA->BAND_FREI();
	return handled;
}


void SA1::showState(){
	cout << "State: SA1" << endl;
	substateSA->showState();
}


