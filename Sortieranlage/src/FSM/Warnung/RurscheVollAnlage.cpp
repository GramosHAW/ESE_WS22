/*
 * RurscheVollAnlage.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "RurscheVollAnlage.h"
#include "BeideRutschenVoll.h"

bool RurscheVollAnlage::RUTSCHE_VOLL_SA2(){
	if(true){//Nur für SA1
		exit();
		new(this) BeideRutschenVoll;
		entry();
		return true;
	}
}

bool RurscheVollAnlage::RUTSCHE_VOLL_SA1(){
	if(true){//Nur für SA2
		exit();
		new(this) BeideRutschenVoll;
		entry();
		return true;
	}
}

bool RurscheVollAnlage::RUTSCHE_VOLL_BEIDE(){
	exit();
	new(this) BeideRutschenVoll;
	entry();
	return true;
}

void RurscheVollAnlage::showState(){
	cout << " SubState: RurscheVollAnlag" << endl;
}

