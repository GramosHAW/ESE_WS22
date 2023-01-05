/*
 * AussortierenInit.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "AussortierenInit.h"
#include "CheckSort.h"
#include "../../../SubEnd.h"

void AussortierenInit::entry() {
	showState();
}
void AussortierenInit::exit() {

}

void AussortierenInit::showState() {
	cout << "  subsubstateAussortieren: AussortierenInit" << endl;
}

bool AussortierenInit::LS_SORT_BLOCK() {
	exit();
	new (this) CheckSort;
	entry();
	return true;
}

bool AussortierenInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}
