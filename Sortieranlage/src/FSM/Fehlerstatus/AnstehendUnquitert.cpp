/*
 * AnstehendUnquitert.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "AnstehendUnquitert.h"
#include "GegangenUnquittiert.h"
#include "AnstehendQuittert.h"


bool AnstehendUnquitert::FEHLER_BEHOBEN(){
	exit();
	new(this) GegangenUnquittiert;
	entry();
	return true;
}

bool AnstehendUnquitert::TST_RESET_KURZ(){
	exit();
	new(this) AnstehendQuittert;
	entry();
	return true;
}

bool AnstehendUnquitert::FEHLER_QUITI(){
	exit();
	new(this) AnstehendQuittert;
	entry();
	return true;
}

void AnstehendUnquitert::showState(){
	cout << " SubStateFEHL: AnstehendUnquitert" << endl;
}


