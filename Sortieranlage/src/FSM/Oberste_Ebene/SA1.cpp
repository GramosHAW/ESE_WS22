/*
 * SA1.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "SA1.h"
#include "Ruhezustand.h"
#include "../ESTOPP/ESTOPP.h"

void SA1::entry() {
	// MSG_SEND_PULSE (BAND_START)
	//send_event_payload(PSMG_SW_BAND_START,0);

}

void SA1::exit() {
	//send_event(PSMG_SW_BAND_STOP);
	// MSG_SEND_PULSE (BAND_STOP)
}

void SA1::entryStartNode() {
	new (substateSA) Ruhezustand;
	substateSA->entry();
}

bool SA1::TST_START_KURZ() {
	bool handled = substateSA->TST_START_KURZ();
	return handled;
}

bool SA1::TST_START_LANG() {
	bool handled = substateSA->TST_START_LANG();
	return handled;
}

bool SA1::TST_STOP_KURZ() {
	bool handled = substateSA->TST_STOP_KURZ();
	return handled;
}

bool SA1::LS_SORT_BLOCK() {
	bool handled = substateSA->LS_SORT_BLOCK();
	return handled;
}

bool SA1::LS_RUTSCHE_BLOCK() {
	bool handled = substateSA->LS_RUTSCHE_BLOCK();
	return handled;
}

bool SA1::ESTOPP_TRUE_SA1() {
	bool handled = substateSA->ESTOPP_TRUE_SA1();
	if (!handled) {
//			substateSA->ESTOPP_TRUE_SA1();
		exit();
		new (this) ESTOPP;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}

bool SA1::LS_START_BLOCK() {
	bool handled = substateSA->LS_START_BLOCK();
	return handled;
}

bool SA1::BAND_FREI() {
	bool handled = substateSA->BAND_FREI();
	return handled;
}

void SA1::showState() {
	cout << "State: SA1" << endl;
	substateSA->showState();
}

bool SA1::HM_START() {
	bool handled = substateSA->HM_START();
	return handled;
}

bool SA1::HM_STOP() {
	bool handled = substateSA->HM_STOP();
	return handled;
}

bool SA1::ELMNT_DURCH() {
	bool handled = substateSA->ELMNT_DURCH();
	return handled;
}
bool SA1::RUTSCHE_FREI() {
	bool handled = substateSA->RUTSCHE_FREI();
	return handled;
}

bool SA1::LS_SORT_FREI() {
	bool handled = substateSA->LS_SORT_FREI();
	return handled;
}
