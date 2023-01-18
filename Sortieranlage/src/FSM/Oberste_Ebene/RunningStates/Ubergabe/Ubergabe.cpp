/*
 * Ubergabe.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "Ubergabe.h"
#include "UbergabeInit.h"
#include "../../../SubEnd.h"

void Ubergabe::entry() {
}

void Ubergabe::exit() {

}

void Ubergabe::showState() {
	cout << "  substateUbergabe: Ubergabe" << endl;
	subsubstateUbergabe->showState();
}

void Ubergabe::initSubState() {
	subsubstateUbergabe = new UbergabeInit;
	subsubstateUbergabe->setData(data);
}

void Ubergabe::entryStartNode() {
	initSubState();
	new (subsubstateUbergabe) UbergabeInit;
	subsubstateUbergabe->entry();
}

bool Ubergabe::LS_ENDE_BLOCK() {
	bool handled = subsubstateUbergabe->LS_ENDE_BLOCK();
	return handled;
}

bool Ubergabe::BAND_FREI() {
	bool handled = subsubstateUbergabe->BAND_FREI();
	if(subsubstateUbergabe->isSubEndState()){
		exit();
		new (this) SubEnd;
		entry();
		return true;
	}
	return handled;
}

bool Ubergabe::BAND_FREI_SA2() {
	bool handled = subsubstateUbergabe->BAND_FREI_SA2();
	return handled;
}


bool Ubergabe::LS_START_BLOCK_SA2() {
	bool handled = subsubstateUbergabe->LS_START_BLOCK_SA2();
	return handled;
}

bool Ubergabe::LS_ENDE_FREI_SA2() {
	bool handled = subsubstateUbergabe->LS_ENDE_FREI_SA2();
	return handled;
}
