/*
 * ESTOPP.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#include "ESTOPP.h"

#include "estoppStart.h"
#include "../Oberste_Ebene/SA1.h"
#include "../Oberste_Ebene/Ruhezustand.h"


void ESTOPP::entryStartNode() {
	new (substateEST) estoppStart;
	substateEST->entry();
}

void ESTOPP::entry() {
	cout << " ESTOPP::entry() | AMPEL ROT AN BLINK, 6hz" << endl;
	send_event_payload(PSMG_SW_AMPEL_ROT_BLINK, 6);
	send_event_payload(PSMG_SW_BAND_STOP, 0);
	send_event_payload(PSMG_SW_AMPEL_ROT_BLINK, 6);
	while(data->Q1.size() != 0){
		data->Q1.pop();
	}
	while(data->QReihenfolge.size() != 0){
		data->QReihenfolge.pop();
	}
#ifndef SIM_TWIN_B
	while(data->Q2.size() != 0){
		data->Q2.pop();
	}
	while(data->Q3.size() != 0){
		data->Q3.pop();
	}
#endif
	data->setrutsche_voll1(false);
	data->setrutsche_voll2(false);
	send_event(PSMG_SW_BAND_SLOW_AUS);
	send_event(PSMG_SW_SORT_AUSSORTIERT);
	// Sort Zu
}

void ESTOPP::exit() {
	cout << " ESTOPP::exit() | " << endl;
	send_event_payload(PSMG_SW_AMPEL_ROT_AUS, 0);
	//send_event_payload(PSMG_SW_AMPEL_GRUEN_AUS,0);
}

bool ESTOPP::ESTOPP_TRUE_SA1() {
	bool handled = substateEST->ESTOPP_TRUE_SA1();
	return handled;
}

bool ESTOPP::ESTOPP_TRUE_SA2() {
	bool handled = substateEST->ESTOPP_TRUE_SA2();
	return handled;
}

bool ESTOPP::ESTOPP_FALSE_SA1() {
	bool handled = substateEST->ESTOPP_FALSE_SA1();
	return handled;
}

bool ESTOPP::ESTOPP_FALSE_SA2() {
	bool handled = substateEST->ESTOPP_FALSE_SA2();
	return handled;
}

bool ESTOPP::ESTOPP_OK_SA1(){
	bool handled = substateEST->ESTOPP_OK_SA1();
	return handled;
}

bool ESTOPP::ESTOPP_OK_SA2(){
	bool handled = substateEST->ESTOPP_OK_SA2();
	return handled;
}

bool ESTOPP::TST_RESET_KURZ() {
	bool handled = substateEST->TST_RESET_KURZ();
	if (substateEST->isSubEndState()) {
		exit();
		new (this) SA1;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}

bool ESTOPP::ESTOPP_QUIT(){
	bool handled = substateEST->ESTOPP_QUIT();
	if (substateEST->isSubEndState()) {
		exit();
		new (this) SA1;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}

//bool ESTOPP::TST_START_KURZ() {
//	bool handled = substateEST->TST_START_KURZ();
//	return handled;
//}

void ESTOPP::showState() {
	cout << "State: EStopp" << endl;
	substateEST->showState();
}

