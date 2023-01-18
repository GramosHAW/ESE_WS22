/*
 * Durchlassen.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "Durchlassen.h"
#include "AussortierenInit.h"

void Durchlassen::entry() {
#ifndef SIM_PUSHER
	send_event(PSMG_SW_SORT_DURCH);
#endif
}

void Durchlassen::exit() {
#ifndef SIM_PUSHER
	send_event(PSMG_SW_SORT_AUSSORTIERT);
#endif
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
