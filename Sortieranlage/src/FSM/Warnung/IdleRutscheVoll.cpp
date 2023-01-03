/*
 * IdleRutscheVoll.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "IdleRutscheVoll.h"
#include "RurscheVollAnlage.h"

bool IdleRutscheVoll::RUTSCHE_VOLL_SA1(){
	if (true){//Nur für SA1
		exit();
		new(this) RurscheVollAnlage;
		entry();
		return true;
	}
}

bool IdleRutscheVoll::RUTSCHE_VOLL_SA2(){
	if (true) {//Nur für SA2
		exit();
		new(this) RurscheVollAnlage;
		entry();
		return true;
	}
}

void IdleRutscheVoll::showState() {
	cout << " SubState: IdleRutscheVoll" << endl;
}
