/*
 * Running.cpp
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */


#include "Running.h"
#include "BIdle.h"

void Running::entry() {
	// MSG_SEND_PULSE (BAND_START)

}

void Running::exit() {
	// MSG_SEND_PULSE (BAND_STOP)
}

bool Running::BAND_FREI(){
	exit();
	new(this) BIdle;
	entry();
	return true;
}

void Running::showState(){
	cout << "  SubstateBZ: Running" << endl;
}

