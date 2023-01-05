/*
 * estoppStart.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#include "estoppStart.h"
#include "estoppResolved.h"
#include "ESTOPP.h"
#include "../Oberste_Ebene/SA1.h"


// ## TO-DO RAUS AUS E-STOPP


void estoppStart::entry(){
	substateEST->showState();
}

void estoppStart::exit() {
	cout << " ESTOPP::exit() | " << endl;
	//send_event_payload(PSMG_SW_AMPEL_ROT_AUS,0);
	//send_event_payload(PSMG_SW_BAND_START, 0);
}

bool estoppStart::ESTOPP_TRUE_SA1() {
	exit();
	new(this) estoppStart;
	entry();
	return true;
}

bool estoppStart::ESTOPP_TRUE_SA2() {
	exit();
	new(this) estoppStart;
	entry();
	return true;
}

bool estoppStart::ESTOPP_FALSE_SA1() {
	exit();
	new(this) estoppResolved;
	entry();
	return true;
}

bool estoppStart::ESTOPP_FALSE_SA2() {
	exit();
	new(this) estoppResolved;
	entry();
	return true;
}


void estoppStart::showState(){
	cout << " substateEST: STATE " << endl;
}
