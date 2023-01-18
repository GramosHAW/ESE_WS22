/*
 * RurscheVollAnlage.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "RurscheVollAnlage.h"
#include "BeideRutschenVoll.h"

bool RurscheVollAnlage::RUTSCHE_VOLL_SA2(){
		exit();
#ifdef SIM_TWIN_B//Nur für SA1
		send_event_payload(PSMG_SW_AMPEL_GELB_AN, 2);
#endif
		data->setrutsche_voll2(true);
		new(this) BeideRutschenVoll;
		entry();
		return true;
}

bool RurscheVollAnlage::RUTSCHE_VOLL_SA1(){
		exit();
#ifndef SIM_TWIN_B
		send_event_payload(PSMG_SW_AMPEL_GELB_AN, 2);
#endif
		data->setrutsche_voll1(true);
		new(this) BeideRutschenVoll;
		entry();
		return true;
}

bool RurscheVollAnlage::RUTSCHE_VOLL_BEIDE(){
	/*
	exit();
#ifdef SIM_TWIN_B
	data->setrutsche_voll1(true);
#else
	data->setrutsche_voll2(true);
#endif
	new(this) BeideRutschenVoll;
	entry();
	return true;
	*/
	return false;
}

void RurscheVollAnlage::showState(){
	cout << " SubState: RurscheVollAnlag" << endl;
}

