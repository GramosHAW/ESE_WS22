/*
 * BeideRutschenVoll.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "BeideRutschenVoll.h"
#include "ErrorRutsche.h"

void BeideRutschenVoll::entry(){
	//send_event_payload(PSMG_SW_RUTSCHE_VOLL_BEIDE, 0);
}

void BeideRutschenVoll::exit(){
	send_event_payload(PSMG_SW_AMPEL_GELB_AUS, 0);
}

bool BeideRutschenVoll::ELMNT_AUSSORT(){
	exit();
	new(this) ErrorRutsche;
	entry();
	return true;
}

void BeideRutschenVoll::showState(){
	cout << " SubState: BeideRutschenVoll" << endl;
}

