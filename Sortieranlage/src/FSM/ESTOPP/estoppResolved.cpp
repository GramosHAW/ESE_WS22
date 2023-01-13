/*
 * estoppResolved.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */



#include "estoppResolved.h"
#include "estoppReset.h"
#include "estoppStart.h"

void estoppResolved::entry() {
	if(true){ //SA1
		send_event_payload(PSMG_ESTOPP_OK_SA1,0);
	} else {  //SA2
		send_event_payload(PSMG_ESTOPP_OK_SA2,0);
	}
}

void estoppResolved::exit() {

}


bool estoppResolved::ESTOPP_TRUE_SA1() {
	exit();
	if(true){ //SA1
		data->setFlagEStopp(true);
		data->showFlags();
	}
	new (this) estoppStart;
	entry();
	return true;
}

bool estoppResolved::ESTOPP_TRUE_SA2() {
	exit();
	if(true){ //SA2
		data->setFlagEStopp(true);
		data->showFlags();
	}
	new (this) estoppStart;
	entry();
	return true;
}
//Übergang für SA1
bool estoppResolved::ESTOPP_OK_SA2() {
	exit();
	send_event_payload(PSMG_ESTOPP_OK_SA1,0);
	new (this) estoppReset;
	entry();
	return true;
}
//Übergang für SA2
bool estoppResolved::ESTOPP_OK_SA1() {
	exit();
	send_event_payload(PSMG_ESTOPP_OK_SA2,0);
	new (this) estoppReset;
	entry();
	return true;
}


//bool estoppResolved::TST_RESET_KURZ() {
//	return true;
//}

//bool estoppResolved::TST_START_KURZ() {
//	exit();
//	new (this) estoppReset;
//	entry();
//	return true;
//}

void estoppResolved::showState() {
	cout << " substateEST: estoppResolved " << endl;
}
