/*
 * WSumgedreht.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "WSumgedreht.h"
#include "IdleFlipped.h"

bool WSumgedreht::WSW_OK(){
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

