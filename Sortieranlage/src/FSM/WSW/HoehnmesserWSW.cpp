/*
 * HoehnmesserWSW.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "HoehnmesserWSW.h"
#include "SortiererWSW.h"

bool HoehnmesserWSW::LS_SORT_BLOCK(){
	exit();
	new(this) SortiererWSW;
	entry();
	return true;
}

void HoehnmesserWSW::showState(){
	cout << " substateWARNRUT: HoehnmesserWSW" << endl;
}

