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
	//TODO DeletFirsWs, setCounter, checkQueue
	/*
	 if(quesize > 0){
	 	 exit();
	 	 new (this) UbergabeInit;
	 	 entry();
	 }
	 else{
	 	 exit();
	 	 new (this) SubEnd;
	 	 entry();
	 }
	 */

}

void CheckQueue::exit() {
	//TODO Send WSW_OK
}

void CheckQueue::showState() {
	cout << "  subsubstateUbergabe: CheckQueue" << endl;

}

