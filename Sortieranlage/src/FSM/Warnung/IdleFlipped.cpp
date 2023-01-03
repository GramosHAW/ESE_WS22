/*
 * IdleFlipped.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "IdleFlipped.h"
#include "WSumgedreht.h"

bool IdleFlipped::WS_FLIPPED(){
	exit();
	new(this) WSumgedreht;
	entry();
	return true;
}

void IdleFlipped::showState(){
	cout << " SubState: IdleFlipped" << endl;
}
