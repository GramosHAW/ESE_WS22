/*
 * AussortiertWSW.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "AussortiertWSW.h"
#include "../SubEnd.h"


bool AussortiertWSW::WSW_OK() {
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

void AussortiertWSW::showState(){
	cout << " substateWARNRUT: AussortiertWSW" << endl;
}
