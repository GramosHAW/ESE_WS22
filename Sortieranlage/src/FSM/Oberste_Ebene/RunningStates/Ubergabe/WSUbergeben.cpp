/*
 * WSUbergeben.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "WSUbergeben.h"
#include "CheckQueue.h"

void WSUbergeben::entry(){
	showState();
	//TODO sendDataToSA2()
}

void WSUbergeben::exit(){

}

void WSUbergeben::showState(){
	cout << "  subsubstateUbergabe: WSUbergeben" << endl;
}

bool WSUbergeben::LS_START_BLOCK_SA2() {
	exit();
	new (this) CheckQueue;
	entry();
	return true;
}