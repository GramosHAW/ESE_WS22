/*
 * Entnahme.cpp
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#include "Entnahme.h"
#include "EntnahmeInit.h"
#include "../../../SubEnd.h"

void Entnahme::entry() {
}

void Entnahme::exit() {

}

void Entnahme::showState() {
	cout << "  substateEntnahme: Entnahme" << endl;
	subsubstateEntnahme->showState();
}

void Entnahme::initSubState() {
	subsubstateEntnahme = new EntnahmeInit;
	subsubstateEntnahme->setData(data);
}

void Entnahme::entryStartNode() {
	initSubState();
	new (subsubstateEntnahme) EntnahmeInit;
	subsubstateEntnahme->entry();
}

bool Entnahme::LS_ENDE_BLOCK() {
	bool handled = subsubstateEntnahme->LS_ENDE_BLOCK();
	return handled;
}

bool Entnahme::LS_ENDE_FREI() {
	bool handled = subsubstateEntnahme->LS_ENDE_FREI();
	if(subsubstateEntnahme->isSubEndState()){
		exit();
		new (this) SubEnd;
		entry();
		return true;
	}
	return handled;
}

bool Entnahme::BAND_FREI() {
	bool handled = subsubstateEntnahme->BAND_FREI();
	if(subsubstateEntnahme->isSubEndState()){
		exit();
		new (this) SubEnd;
		entry();
		return true;
	}
	return handled;
}
