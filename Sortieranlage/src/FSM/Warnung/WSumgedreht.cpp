/*
 * WSumgedreht.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "WSumgedreht.h"
#include "IdleFlipped.h"

void WSumgedreht::entry(){
	send_event_payload(PSMG_SW_AMPEL_GELB_BLINK, 1);
}

void WSumgedreht::exit(){
	send_event(PSMG_SW_AMPEL_GELB_AUS);
	send_event(PSMG_SW_AMPEL_GRUEN_AN);
}


bool WSumgedreht::BAND_FREI(){
	exit();
	new(this) IdleFlipped;
	entry();
	return true;
}

bool WSumgedreht::ELMNT_AUSSORT(){
	exit();
	new(this) IdleFlipped;
	entry();
	return true;
}



void WSumgedreht::showState(){
	cout << " SubState: WSumgedreht" << endl;
}

