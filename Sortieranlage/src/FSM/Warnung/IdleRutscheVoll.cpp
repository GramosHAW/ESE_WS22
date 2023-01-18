/*
 * IdleRutscheVoll.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "IdleRutscheVoll.h"
#include "RurscheVollAnlage.h"

void IdleRutscheVoll::entry() {
}

bool IdleRutscheVoll::RUTSCHE_VOLL_SA1() {
	exit();
#ifndef SIM_TWIN_B//Nur für SA1
	send_event_payload(PSMG_SW_AMPEL_GELB_AN, 2);
#endif
	data->setrutsche_voll1(true);
	new (this) RurscheVollAnlage;
	entry();
	return true;

}

bool IdleRutscheVoll::RUTSCHE_VOLL_SA2() {
	exit();
#ifdef SIM_TWIN_B//Nur für SA2
	send_event_payload(PSMG_SW_AMPEL_GELB_AN, 2);
#endif
	data->setrutsche_voll2(true);
	new (this) RurscheVollAnlage;
	entry();
	return true;

}

void IdleRutscheVoll::showState() {
	cout << " SubState: IdleRutscheVoll" << endl;
}
