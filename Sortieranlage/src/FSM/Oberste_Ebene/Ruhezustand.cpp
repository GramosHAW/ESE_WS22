/*
 * Ruhezustand.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "Ruhezustand.h"
#include "Betrieb.h"
#include "ServiceModus/Service.h"
#include "Bidle.h"
#include "../BaseState.h"
#include "ServiceModus/Standby.h"


void Ruhezustand::initSubState(){
	substateBZ = new BIdle;
	substateSERV = new Standby;
}

void Ruhezustand::entry() {
	cout << "Ruhezustand::entry() aufgerufen" << " | AMPEL ROT BLINK" <<endl;
	//send_event_payload(PSMG_SW_AMPEL_ROT_BLINK,3);
}

void Ruhezustand::exit(){
	cout << "Ruhezustand::exit() aufgerufen" << " | AMPEL ROT AUS" << endl;
	send_event_payload(PSMG_SW_AMPEL_ROT_AUS,0);
}


bool Ruhezustand::TST_START_KURZ(){
	exit();
	new(this) Betrieb;
	entry();
	entryStartNode();
	return true;
}

bool Ruhezustand::TST_START_LANG(){
	exit();
	new(this) Service;
	entry();
	return true;
}


bool Ruhezustand::SERVICE(){
	exit();
	new(this) Service;
	entry();
	entryStartNode();
	return true;
}

bool Ruhezustand::BETRIEB(){
	exit();
	new(this) Betrieb;
	entry();
	entryStartNode();
	return true;
}



void Ruhezustand::showState(){
	cout << " SubstateSA: Ruhezustand" << endl;
}



