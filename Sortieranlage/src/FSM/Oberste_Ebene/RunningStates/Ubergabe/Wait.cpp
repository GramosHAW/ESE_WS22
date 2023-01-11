/*
 * Wait.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "Wait.h"
#include "WSUbergeben.h"

void Wait::entry(){
	showState();
	//TODO all etrise
}

//TODO do

void Wait::exit(){
	//TODo all exit
}

void Wait::showState(){
	cout << "  subsubstateUbergabe: Wait" << endl;
}

bool Wait::BAND_FREI_SA2(){
	exit();
	new (this) WSUbergeben;
	entry();
	return true;
}
