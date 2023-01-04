/*
 * GegangenUnquittiert.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "GegangenUnquittiert.h"
#include "../SubEnd.h"
#include "AnstehendUnquitert.h"

bool GegangenUnquittiert::FEHLER_TRUE(){
	exit();
	new(this) AnstehendUnquitert;
	entry();
	return true;
}

bool GegangenUnquittiert::FEHLER_QUITI(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}
bool GegangenUnquittiert::TST_RESET_KURZ(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

void GegangenUnquittiert::showState(){
	cout << " SubStateFEHL: GegangenUnquittiert" << endl;
}

