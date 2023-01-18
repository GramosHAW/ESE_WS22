/*
 * RurscheVollAnlage.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "RurscheVollAnlage.h"
#include "BeideRutschenVoll.h"

bool RurscheVollAnlage::RUTSCHE_VOLL_SA2(){
#ifndef SIM_TWIN_B//Nur für SA1
		exit();
		data->setrutsche_voll2(true);
		new(this) BeideRutschenVoll;
		entry();
		return true;
#endif
		return false;
}

bool RurscheVollAnlage::RUTSCHE_VOLL_SA1(){
#ifdef SIM_TWIN_B
		exit();
		data->setrutsche_voll1(true);
		new(this) BeideRutschenVoll;
		entry();
		return true;
#endif
		return false;
}

bool RurscheVollAnlage::RUTSCHE_VOLL_BEIDE(){
	exit();
#ifdef SIM_TWIN_B
	data->setrutsche_voll1(true);
#else
	data->setrutsche_voll2(true);
#endif
	new(this) BeideRutschenVoll;
	entry();
	return true;
}

void RurscheVollAnlage::showState(){
	cout << " SubState: RurscheVollAnlag" << endl;
}

