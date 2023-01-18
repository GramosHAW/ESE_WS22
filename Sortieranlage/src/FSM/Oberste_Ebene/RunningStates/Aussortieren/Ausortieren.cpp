/*
 * Ausortieren.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "Ausortieren.h"
#include "AussortierenInit.h"
#include "../../../SubEnd.h"

void Ausortieren::entry() {
	//TODO checksort()
}

void Ausortieren::exit() {

}

void Ausortieren::showState() {
	cout << "substateAussortieren: Ausortieren" << endl;
	subsubstateAussortieren->showState();
}

void Ausortieren::entryStartNode() {
	initSubState();
	new (subsubstateAussortieren) AussortierenInit;
	subsubstateAussortieren->entry();
}

void Ausortieren::initSubState() {
	subsubstateAussortieren = new AussortierenInit;
	subsubstateAussortieren->setData(data);
}

bool Ausortieren::BAND_FREI() {
	bool handled = subsubstateAussortieren->BAND_FREI();
	if(subsubstateAussortieren->isSubEndState()){
		exit();
		new (this) SubEnd;
		entry();
		return true;
	}
	return handled;
}

bool Ausortieren::LS_SORT_BLOCK() {
	bool handled = subsubstateAussortieren->LS_SORT_BLOCK();
	return handled;
}

bool Ausortieren::LS_SORT_FREI() {
	bool handled = subsubstateAussortieren->LS_SORT_FREI();
	return handled;
}
bool Ausortieren::ELMNT_AUSSORT() {
	bool handled = subsubstateAussortieren->ELMNT_AUSSORT();
	return handled;
}

bool Ausortieren::ELMNT_DURCH() {
	bool handled = subsubstateAussortieren->ELMNT_DURCH();
	return handled;
}

bool Ausortieren::LS_RUTSCHE_FREI() {
	bool handled = subsubstateAussortieren->LS_RUTSCHE_FREI();
	return handled;
}
