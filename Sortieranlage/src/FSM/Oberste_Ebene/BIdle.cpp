/*
 * BIdle.cpp
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */


#include "BIdle.h"
#include "Running.h"
#include "../SubEnd.h"




void BIdle::entry() {
	//not like in the schematic
	showState();
	send_event_payload(PSMG_SW_BAND_STOP,0);
}

void BIdle::exit() {

}

bool BIdle::LS_START_FREI(){
	exit();
	new(this) BIdle;
	entry();
	return true;
}

bool BIdle::LS_START_BLOCK(){
	exit();
	new(this) Running;
	entry();
	return true;
}

bool BIdle::TST_STOP_KURZ(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

void BIdle::showState(){
	cout << "  SubstateBZ: BIdle" << endl;
}
