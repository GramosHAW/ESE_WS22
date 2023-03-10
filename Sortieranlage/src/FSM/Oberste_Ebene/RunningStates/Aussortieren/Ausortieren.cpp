/*
 * Ausortieren.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "Ausortieren.h"
#include "AussortierenInit.h"

void Ausortieren::entry() {
	showState();
	//TODO checksort()
}

void Ausortieren::exit() {

}

void Ausortieren::showState() {
	cout << "  substateAussortieren: Ausortieren" << endl;
}

void Ausortieren::entryStartNode() {
	initSubState();
	new (subsubstateAussortieren) AussortierenInit;
	subsubstateAussortieren->entry();
}

void Ausortieren::initSubState() {
	subsubstateAussortieren = new AussortierenInit;
}

bool Ausortieren::BAND_FREI() {
	bool handled = substateAussortieren->BAND_FREI();
	return handled;
}

bool Ausortieren::LS_SORT_BLOCK() {
	bool handled = substateAussortieren->LS_SORT_BLOCK();
	return handled;
}

bool Ausortieren::LS_SORT_FREI() {
	bool handled = substateAussortieren->LS_SORT_FREI();
	return handled;
}
bool Ausortieren::ELMNT_AUSSORT() {
	bool handled = substateAussortieren->ELMNT_AUSSORT();
	return handled;
}

bool Ausortieren::ELMNT_DURCH() {
	bool handled = substateAussortieren->ELMNT_DURCH();
	return handled;
}

bool Ausortieren::RUTSCHE_FREI() {
	bool handled = substateAussortieren->RUTSCHE_FREI();
	return handled;
}
