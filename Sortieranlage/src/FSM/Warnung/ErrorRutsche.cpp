/*
 * ErrorRutsche.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "ErrorRutsche.h"
#include "IdleRutscheVoll.h"

void ErrorRutsche::entry(){
	send_event_payload(PSMG_SW_FEHLER_TRUE, 0);
}

bool ErrorRutsche::FEHLER_BEHOBEN(){
	exit();

	new(this) IdleRutscheVoll;
	entry();
	return true;
}

void ErrorRutsche::showState(){
	cout << " SubState: ErrorRutsche" << endl;
}

