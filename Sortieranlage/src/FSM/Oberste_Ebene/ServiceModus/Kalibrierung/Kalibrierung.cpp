/*
 * Kalibrierung.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "Kalibrierung.h"
#include "SortiererEinstellen.h"

void Kalibrierung::entry() {
	//substateKALI->showState();
	this->showState();
}

void Kalibrierung::exit() {

}

void Kalibrierung::entryStartNode(){
	//initSubState();
	new(substateKALI) SortiererEinstellen;
	substateKALI->entry();
}

void Kalibrierung::initSubState() {
	substateKALI = new SortiererEinstellen;
}

bool Kalibrierung::TST_START_KURZ() {
	bool handled = substateKALI->TST_START_KURZ();
	return handled;
}
bool Kalibrierung::TST_START_LANG() {
	bool handled = substateKALI->TST_START_LANG();
	return handled;
}

bool Kalibrierung::TST_RESET_KURZ() {
	bool handled = substateKALI->TST_RESET_KURZ();
	return handled;
}

bool Kalibrierung::HM_START() {
	bool handled = substateKALI->HM_START();
	return handled;
}
bool Kalibrierung::LS_START_BLOCK() {
	bool handled = substateKALI->LS_START_BLOCK();
	return handled;
}

bool Kalibrierung::LS_SORT_BLOCK() {
	bool handled = substateKALI->LS_SORT_BLOCK();
	return handled;
}
bool Kalibrierung::LS_ENDE_BLOCK() {
	bool handled = substateKALI->LS_ENDE_BLOCK();
	return handled;
}
bool Kalibrierung::LS_RUTSCHE_BLOCK() {
	bool handled = substateKALI->LS_RUTSCHE_BLOCK();
	return handled;
}

void Kalibrierung::showState() {
	cout << " >> <SubState> Kalibrierung " << endl;
	substateKALI->showState();
}


