/*
 * estoppReset.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */


#include "estoppReset.h"
#include "../Oberste_Ebene/Ruhezustand.h"
#include "../SubEnd.h"


void estoppReset::entry() {
	send_event_payload(PSMG_SW_AMPEL_GRUEN_BLINK, 4);
}

void estoppReset::exit() {
	send_event_payload(PSMG_SW_AMPEL_GRUEN_AUS,0);

}

bool estoppReset::ESTOPP_FALSE_SA1() {
	bool handled = substateEST->ESTOPP_FALSE_SA1();
	return handled;
}

bool estoppReset::TST_RESET_KURZ() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

void estoppReset::showState() {
	cout << " RESET STATE " << endl;
}
