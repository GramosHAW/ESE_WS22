/*
 * BIdle.cpp
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */


#include "BIdle.h"
#include "Running.h"
#include "Respond.h"
#include "../SubEnd.h"




void BIdle::entry() {
	//not like in the schematic
	showState();
	send_event_payload(PSMG_SW_BAND_STOP,0);
}

void BIdle::exit() {

}

//bool BIdle::LS_START_FREI(){
//	exit();
//	new(this) BIdle;
//	entry();
//	return true;
//}

bool BIdle::LS_START_BLOCK(){
	if(true){ //Nur für SA1
		exit();
		new(this) Running;
		entry();
		return true;
	}
}

bool BIdle::TST_STOP_KURZ(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

bool BIdle::RUHE(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

bool BIdle::BAND_STATUS(){
	if (true){ //Nur für SA2
		exit();
		new(this) Respond;
		entry();
		return true;
	}
}

void BIdle::showState(){
	cout << "  SubstateBZ: BIdle" << endl;
}
