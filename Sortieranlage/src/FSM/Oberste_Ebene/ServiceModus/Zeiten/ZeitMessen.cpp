/*
 * ZeitMessen.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "ZeitMessen.h"
#include "BandAnfang.h"

void ZeitMessen::entry() {
	this->showState();
}

void ZeitMessen::exit() {

}

void ZeitMessen::initSubState() {
	substateZEIT = new BandAnfang;
}

void ZeitMessen::entryStartNode(){
	//initSubState();
	new(substateZEIT) BandAnfang;
	substateZEIT->entry();
}

bool ZeitMessen::TST_START_KURZ() {
	bool handled = substateZEIT->TST_START_KURZ();
	return handled;
}
bool ZeitMessen::TST_START_LANG() {
	bool handled = substateZEIT->TST_START_LANG();
	return handled;
}

bool ZeitMessen::TST_RESET_KURZ() {
	bool handled = substateZEIT->TST_RESET_KURZ();
	return handled;
}

bool ZeitMessen::HM_START() {
	bool handled = substateZEIT->HM_START();
	return handled;
}
bool ZeitMessen::LS_START_BLOCK() {
	bool handled = substateZEIT->LS_START_BLOCK();
	return handled;
}

bool ZeitMessen::LS_SORT_BLOCK() {
	bool handled = substateZEIT->LS_SORT_BLOCK();
	return handled;
}
bool ZeitMessen::LS_ENDE_BLOCK() {
	bool handled = substateZEIT->LS_ENDE_BLOCK();
	return handled;
}
bool ZeitMessen::LS_RUTSCHE_BLOCK() {
	bool handled = substateZEIT->LS_RUTSCHE_BLOCK();
	return handled;
}

void ZeitMessen::showState() {
	cout << " >> >> <SubSubState> ZeitMessen " << endl;
	substateZEIT->showState();
}




