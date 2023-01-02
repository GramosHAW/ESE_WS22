/*
 * Ruhezustand.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "Ruhezustand.h"
#include "Betrieb.h"
#include "Service.h"
#include "Bidle.h"

void Ruhezustand::initSubState(){
	substateBZ = new BIdle;
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

void Ruhezustand::showState(){
	cout << " SubstateSA: Ruhezustand" << endl;
}



