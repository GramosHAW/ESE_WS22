/*
 * ErrorRutsche.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "ErrorRutsche.h"
#include "IdleRutscheVoll.h"

bool ErrorRutsche::FEHLER_BEHOBEN(){
	exit();
	new(this) IdleRutscheVoll;
	entry();
	return true;
}

void ErrorRutsche::showState(){
	cout << " SubState: ErrorRutsche" << endl;
}

