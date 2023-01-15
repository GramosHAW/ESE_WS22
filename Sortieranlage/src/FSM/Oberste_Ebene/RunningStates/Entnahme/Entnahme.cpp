/*
 * Entnahme.cpp
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#include "Entnahme.h"
#include "EntnahmeInit.h"

void Entnahme::entry() {
	showState();
}

void Entnahme::exit() {

}

void Entnahme::showState() {
	cout << "  substateEntnahme: Entnahme" << endl;
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
	return handled;
}
