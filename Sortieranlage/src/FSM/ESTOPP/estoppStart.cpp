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
	send_event_payload(PSMG_SW_AMPEL_ROT_BLINK, 6);
}

void estoppStart::exit() {
	//send_event_payload(PSMG_SW_AMPEL_ROT_AUS,0);
	//send_event_payload(PSMG_SW_BAND_START, 0);
}

bool estoppStart::ESTOPP_TRUE_SA1() {
#ifndef SIM_TWIN_B //SA1
		exit();
		data->setFlagEStopp(true);
		data->showFlags();
		new(this) estoppStart;
		entry();
		return true;
#endif
		return false;
}

bool estoppStart::ESTOPP_TRUE_SA2() {
#ifdef SIM_TWIN_B //SA2
		exit();
		data->setFlagEStopp(true);
		data->showFlags();
		new(this) estoppStart;
		entry();
		return true;
#endif
		return false;
}

bool estoppStart::ESTOPP_FALSE_SA1() {
#ifndef SIM_TWIN_B //SA1
		exit();
		data->setFlagEStopp(false);
		data->showFlags();
		new(this) estoppResolved;
		entry();
		return true;
#else	//SA2
		if(!data->getEStopp()){
			exit();
			new(this) estoppResolved;
			entry();
			return true;
		}
		return false;
#endif

}

bool estoppStart::ESTOPP_FALSE_SA2() {
#ifdef SIM_TWIN_B //SA2
		exit();
		data->setFlagEStopp(false);
		data->showFlags();
		new(this) estoppResolved;
		entry();
		return true;
#else //SA1
		if(!data->getEStopp()){
			exit();
			new(this) estoppResolved;
			entry();
			return true;
		}
		return false;
#endif
}


void estoppStart::showState(){
	cout << " substateEST: estoppStart " << endl;
}
