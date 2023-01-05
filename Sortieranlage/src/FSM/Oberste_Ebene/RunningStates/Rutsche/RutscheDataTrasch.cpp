/*
 * RutscheDataTrasch.cpp
 *
 *  Created on: 27 Dec 2022
 *      Author: andre
 */

#include "RutscheDataTrasch.h"
#include "RutscheInit.h"
#include "../../../SubEnd.h"

void RutscheDataTrasch::entry() {
	showState();
	//TODO traschData()
}

void RutscheDataTrasch::exit() {

}

void RutscheDataTrasch::showState() {
	cout << "  subsubstateRutsche: RutscheDataTrasch" << endl;
}

bool RutscheDataTrasch::LS_RUTSCHE_FREI() {
	exit();
	new (this) RutscheInit;
	entry();
	return true;
}

bool RutscheDataTrasch::RUTSCHE_VOLL_SA1() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

