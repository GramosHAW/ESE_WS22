/*
 * BandAnfang.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "BandAnfangWSW.h"
#include "HoehnmesserWSW.h"

bool BandAnfangWSW::HM_START(){
	exit();
	new(this) HoehnmesserWSW;
	entry();
	return true;
}

void BandAnfangWSW::showState(){
	cout << " substateWARNRUT: BandAnfang" << endl;
}
