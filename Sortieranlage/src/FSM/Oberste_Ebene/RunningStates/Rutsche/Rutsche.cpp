/*
 * Rutsche.cpp
 *
 *  Created on: 27 Dec 2022
 *      Author: andre
 */

#include "Rutsche.h"
#include "RutscheInit.h"

void Rutsche::entry() {
	showState();
}
void Rutsche::exit() {

}

void Rutsche::showState() {
	cout << "  substateRutsche: Rutsche" << endl;
}

void Rutsche::initSubState() {
	subsubstateRutsche = new RutscheInit;
	subsubstateRutsche->setData(data);
}

void Rutsche::entryStartNode() {
	initSubState();
	new (subsubstateRutsche) RutscheInit;
	subsubstateRutsche->entry();
}

bool Rutsche::BAND_FREI() {
	bool handled = subsubstateRutsche->BAND_FREI();
	return handled;
}

bool Rutsche::LS_RUTSCHE_BLOCK() {
	bool handled = subsubstateRutsche->LS_RUTSCHE_BLOCK();
	return handled;
}

bool Rutsche::LS_RUTSCHE_FREI() {
	bool handled = subsubstateRutsche->LS_RUTSCHE_FREI();
	return handled;
}

bool Rutsche::RUTSCHE_VOLL_SA1() {
	bool handled = subsubstateRutsche->RUTSCHE_VOLL_SA1();
	return handled;
}

