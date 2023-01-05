/*
 * UebergangWSW.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "UebergangWSW.h"
#include "../SubEnd.h"

bool UebergangWSW::WSW_OK(){
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

void UebergangWSW::showState(){
	cout << " substateWARNRUT: UebergangWSW" << endl;
}

