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
#ifdef SIM_PUSHER
	send_event(PSMG_SW_SORT_DURCH);
#endif
}

void DoAussortieren::exit() {
#ifdef SIM_PUSHER
	send_event(PSMG_SW_SORT_AUSSORTIERT);
#endif
}

void DoAussortieren::showState() {
	cout << "  subsubstateAussortieren: DoAussortieren" << endl;
}

bool DoAussortieren::LS_RUTSCHE_FREI() {
	exit();
	printf("hallo Rutsche frei\n");
	new (this) AussortierenInit;
	entry();
	return true;
}
