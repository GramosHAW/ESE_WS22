/*
 * Betrieb.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "Betrieb.h"
#include "Ruhezustand.h"
#include "BIdle.h"
#include "../../HAL/Aktorik.h"
#include "../../Events.h"


//Aktorik *aktorik = new Aktorik();

void Betrieb::entry() {
	send_event_payload(PSMG_SW_AMPEL_GRUEN_AN,0);
}

void Betrieb::exit() {
	send_event_payload(PSMG_SW_AMPEL_GRUEN_AUS,0);
	//zu ersetzen mit MSG_SEND_PULSE
	//aktorik->ampelGruenAus();
}

void Betrieb::entryStartNode(){
	new(substateBZ) BIdle;
	substateBZ->entry();
}

bool Betrieb::TST_STOP_KURZ(){
	bool handled = substateBZ->TST_STOP_KURZ();
		if(substateBZ->isSubEndState()){
			exit();
			new(this) Ruhezustand;
			entry();
			handled = true;
		}
	return handled;
}



bool Betrieb::LS_START_BLOCK(){
	bool handled = substateBZ->LS_START_BLOCK();
	return handled;
}

bool Betrieb::LS_SORT_BLOCK() {
	bool handled = substateBZ->LS_SORT_BLOCK();
	return handled;
}

bool Betrieb::LS_RUTSCHE_BLOCK() {
	bool handled = substateBZ->LS_RUTSCHE_BLOCK();
	return handled;
}

bool Betrieb::BAND_FREI(){
	bool handled = substateBZ->BAND_FREI();
	return handled;
}



void Betrieb::showState(){
	cout << " SubstateSA: Betrieb" << endl;
	substateBZ->showState();
}
