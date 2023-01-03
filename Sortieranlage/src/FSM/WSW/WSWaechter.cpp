/*
 * WSWaechter.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "WSWaechter.h"

#include "BandAnfangWSW.h"
#include "WSWError.h"

void WSWaechter::entryStartNode(){
	new (substateWSW) BandAnfangWSW;
	substateWSW->entry();
}

void WSWaechter::entryHistory(){

}

void WSWaechter::initSubState(){
	substateWSW = new BandAnfangWSW;
}

bool WSWaechter::HM_START(){
	bool handled = substateWSW->HM_START();
	return handled;
}

bool WSWaechter::LS_SORT_BLOCK(){
	bool handled = substateWSW->LS_SORT_BLOCK();
	return handled;
}

bool WSWaechter::LS_ENDE_BLOCK(){
	bool handled = substateWSW->LS_ENDE_BLOCK();
	return handled;
}

bool WSWaechter::LS_RUTSCHE_BLOCK(){
	bool handled = substateWSW->LS_RUTSCHE_BLOCK();
	return handled;
}

bool WSWaechter::LS_ENDE_BLOCK_SA2(){
	bool handled = substateWSW->LS_ENDE_BLOCK_SA2();
	return handled;
}

bool WSWaechter::WSW_OK(){
	bool handled = substateWSW->WSW_OK();
	return handled;
}

bool WSWaechter::FEHLER_WSW(){
	bool handled = substateWSW->FEHLER_WSW();
	if (!handled){
		exit();
		new(this) WSWError;
		entry();
		handled = true;
	}
	return handled;
}



void WSWaechter::showState() {
	cout << "State: WSWaechter" << endl;
	substateWSW->showState();
}
