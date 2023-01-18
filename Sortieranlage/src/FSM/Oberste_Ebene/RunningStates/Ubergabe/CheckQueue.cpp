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
	showState();
	//TODO DeletFirsWs, setCounter,
	data->Q3.pop();
	checkQueue();
}

void CheckQueue::exit() {
	//TODO Send WSW_OK
}


void CheckQueue::checkQueue(){
	if(data->Q3.size() <= 1){
	 	 exit();
	 	 new (this) UbergabeInit;
	 	 entry();
	} else {
	 	 exit();
	 	 new (this) SubEnd;
	 	 entry();
	}
}


void CheckQueue::showState() {
	cout << "  subsubstateUbergabe: CheckQueue" << endl;

}

