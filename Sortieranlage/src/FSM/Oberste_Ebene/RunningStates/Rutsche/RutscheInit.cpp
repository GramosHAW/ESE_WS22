/*
 * RutscheInit.cpp
 *
 *  Created on: 27 Dec 2022
 *      Author: andre
 */

#include "RutscheInit.h"
#include "../../../SubEnd.h"

void RutscheInit::entry() {
#ifdef SIM_TWIN_B
	printf("Rusche init SA2 \n");
	data->Q1.printContents();
	if(data->Q1.size()== 0){
		send_event(PSMG_SW_BAND_FREI);
		send_event(PSMG_SW_BAND_FREI_SA2);
	}
#else
	printf("Rusche init SA1 \n");
	data->Q1.printContents();
	if((data->Q1.size()== 0) && (data->Q2.size()== 0) && (data->Q3.size()== 0)){
		send_event(PSMG_SW_BAND_FREI);
	}

#endif
}

void RutscheInit::exit() {

}

void RutscheInit::showState() {
	cout << "  subsubstateRutsche: RutscheInit" << endl;
}

bool RutscheInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

bool RutscheInit::LS_RUTSCHE_BLOCK() {
	exit();
	new (this) RutscheInit;
	entry();
	return true;
}

