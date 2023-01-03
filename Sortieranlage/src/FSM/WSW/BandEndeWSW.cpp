/*
 * BandEnde.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "BandEndeWSW.h"
#include "UebergangWSW.h"
#include "../SubEnd.h"


bool BandEndeWSW::LS_ENDE_BLOCK_SA2(){
	if(true){ //Nur für SA1
		exit();
		new(this) UebergangWSW;
		entry();
		return true;
	}
}

bool BandEndeWSW::WSW_OK(){
	if(true){ //Nur für SA2
		exit();
		new(this) SubEnd;
		entry();
		return true;
	}
}

void BandEndeWSW::showState(){
	cout << " substateWARNRUT: BandEnde" << endl;
}

