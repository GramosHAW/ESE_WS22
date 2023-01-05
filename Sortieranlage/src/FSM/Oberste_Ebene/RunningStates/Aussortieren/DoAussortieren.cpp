/*
 * DoAussortieren.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "DoAussortieren.h"
#include "AussortierenInit.h"

void DoAussortieren::entry() {
	showState();
}

void DoAussortieren::exit() {

}

void DoAussortieren::showState() {
	cout << "  subsubstateAussortieren: DoAussortieren" << endl;
}

bool DoAussortieren::LS_RUTSCHE_FREI() {
	exit();
	new (this) AussortierenInit;
	entry();
	return true;
}
