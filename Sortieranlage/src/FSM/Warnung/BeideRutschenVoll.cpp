/*
 * BeideRutschenVoll.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "BeideRutschenVoll.h"
#include "ErrorRutsche.h"

bool BeideRutschenVoll::ELMNT_AUSSORT(){
	exit();
	new(this) ErrorRutsche;
	entry();
	return true;
}

void BeideRutschenVoll::showState(){
	cout << " SubState: BeideRutschenVoll" << endl;
}

