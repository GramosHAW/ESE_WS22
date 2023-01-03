/*
 * RutscheVoll.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "RutscheVoll.h"
#include "IdleRutscheVoll.h"

void RutscheVoll::entryStartNode(){
	new (substateWARNRUT) IdleRutscheVoll;
	substateWARNRUT->entry();
}
void RutscheVoll::initSubState(){
	substateWARNRUT = new IdleRutscheVoll;
}

bool RutscheVoll::RUTSCHE_VOLL_SA1(){
	bool handled = substateWARNRUT->RUTSCHE_VOLL_SA1();
	return handled;
}
bool RutscheVoll::RUTSCHE_VOLL_SA2(){
	bool handled = substateWARNRUT->RUTSCHE_VOLL_SA2();
	return handled;
}
bool RutscheVoll::RUTSCHE_VOLL_BEIDE(){
	bool handled = substateWARNRUT->RUTSCHE_VOLL_BEIDE();
	return handled;
}

bool RutscheVoll::ELMNT_AUSSORT(){
	bool handled = substateWARNRUT->ELMNT_AUSSORT();
	return handled;
}
bool RutscheVoll::FEHLER_BEHOBEN(){
	bool handled = substateWARNRUT->FEHLER_BEHOBEN();
	return handled;
}

void RutscheVoll::showState() {
	cout << "State: RutscheVoll" << endl;
	substateWARNRUT->showState();
}
