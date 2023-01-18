/*
 * IdleRutscheVoll.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "IdleRutscheVoll.h"
#include "RurscheVollAnlage.h"

void IdleRutscheVoll::entry(){
	send_event_payload(PSMG_SW_AMPEL_GELB_AN, 0);
}

bool IdleRutscheVoll::RUTSCHE_VOLL_SA1(){
#ifndef SIM_TWIN_B//Nur für SA1
		exit();
		data->setrutsche_voll1(true);
		new(this) RurscheVollAnlage;
		entry();
		return true;
#endif
		return false;
}

bool IdleRutscheVoll::RUTSCHE_VOLL_SA2(){
#ifdef SIM_TWIN_B//Nur für SA2
		exit();
		data->setrutsche_voll2(true);
		new(this) RurscheVollAnlage;
		entry();
		return true;
#endif
		return false;
}

void IdleRutscheVoll::showState() {
	cout << " SubState: IdleRutscheVoll" << endl;
}
