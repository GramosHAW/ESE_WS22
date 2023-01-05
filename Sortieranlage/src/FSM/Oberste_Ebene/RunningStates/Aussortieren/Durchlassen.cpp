/*
 * Durchlassen.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "Durchlassen.h"
#include "AussortierenInit.h"

void Durchlassen::entry() {
	showState();
	//TODO SortAuf()
}

void Durchlassen::exit() {
	//TODO SortZu()
}

void Durchlassen::showState() {
	cout << "  subsubstateAussortieren: Durchlassen" << endl;
}

bool Durchlassen::LS_SORT_FREI() {
	exit();
	new (this) AussortierenInit;
	entry();
	return true;
}
