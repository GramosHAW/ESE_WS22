/*
 * SortiererWSW.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "SortiererWSW.h"
#include "AussortiertWSW.h"
#include "BandEndeWSW.h"


bool SortiererWSW::LS_ENDE_BLOCK(){
	exit();
	new(this) AussortiertWSW;
	entry();
	return true;
}

bool SortiererWSW::LS_RUTSCHE_BLOCK(){
	exit();
	new(this) BandEndeWSW;
	entry();
	return true;
}

void SortiererWSW::showState(){
	cout << " substateWARNRUT: SortiererWSW" << endl;
}


