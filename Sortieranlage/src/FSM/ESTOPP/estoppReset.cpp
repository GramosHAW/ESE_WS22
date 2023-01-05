/*
 * estoppReset.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */


#include "estoppReset.h"
#include "estoppStart.h"
#include "../SubEnd.h"


void estoppReset::entry() {
	send_event_payload(PSMG_SW_AMPEL_GRUEN_BLINK, 4);
}

void estoppReset::exit() {
	send_event_payload(PSMG_SW_AMPEL_GRUEN_AUS,0);

}

bool estoppReset::ESTOPP_TRUE_SA1() {
	exit();
	new (this) estoppStart;
	entry();
	return true;
}

bool estoppReset::ESTOPP_TRUE_SA2() {
	exit();
	new (this) estoppStart;
	entry();
	return true;
}

bool estoppReset::TST_RESET_KURZ() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

bool estoppReset::ESTOPP_QUIT(){
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

void estoppReset::showState() {
	cout << " substateEST: estoppReset" << endl;
}
