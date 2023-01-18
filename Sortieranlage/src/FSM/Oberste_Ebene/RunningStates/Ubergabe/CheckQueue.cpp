/*
 * CheckQueue.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "CheckQueue.h"
#include "../../../SubEnd.h"
#include "UbergabeInit.h"

void CheckQueue::entry() {
	//TODO DeletFirsWs, setCounter,
	data->Q3.pop();
	checkQueue();
}

void CheckQueue::exit() {
	//TODO Send WSW_OK
}


void CheckQueue::checkQueue(){
	if(data->Q3.size() == 0 && data->Q1.size() == 0 && data->Q2.size() == 0){
	 	 exit();
	 	 send_event_payload(PSMG_SW_BAND_FREI, 0);
	 	 new (this) SubEnd;
	 	 entry();
	} else {
	 	 exit();
	 	 new (this) UbergabeInit;
	 	 entry();
	}
}


void CheckQueue::showState() {
	cout << "  subsubstateUbergabe: CheckQueue" << endl;

}

