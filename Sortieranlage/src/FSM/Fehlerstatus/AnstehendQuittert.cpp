/*
 * AnstehendQuittert.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "../SubEnd.h"
#include "AnstehendQuittert.h"
#include "AnstehendUnquitert.h"

bool AnstehendQuittert::FEHLER_BEHOBEN(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

bool AnstehendQuittert::FEHLER_TRUE(){
	exit();
	new(this) AnstehendUnquitert;
	entry();
	return true;
}

void AnstehendQuittert::showState(){
	cout << " SubStateFEHL: AnstehendQuittert" << endl;
}
