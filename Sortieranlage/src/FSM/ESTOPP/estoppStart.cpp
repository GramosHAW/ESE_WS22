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
	bool handled = substateEST->ESTOPP_TRUE_SA1();
	return handled;
}

bool estoppStart::ESTOPP_FALSE_SA1() {
	exit();
	cout << " hELLo " << endl;
	new(this) estoppResolved;
	entry();

	return true;
}

bool estoppStart::ESTOPP_FALSE_SA2() {
	return false;
}

bool estoppStart::TST_STOP_KURZ() {
	return false;
}

bool estoppStart::TST_START_KURZ() {
	return false;
}

void estoppStart::showState(){
	cout << " estoppStart STATE " << endl;
}


// ## TEST ## NOCH ZU VERLAGERN ZU ESTOPPRESET

bool estoppStart::TST_RESET_KURZ() {
	bool handled = substateEST->TST_RESET_KURZ();
		if(substateEST->isSubEndState()) {
			exit();
			new(this) SA1;
			entry();
			//entryStartNode();
			handled = true;
		}
	return handled;

}
