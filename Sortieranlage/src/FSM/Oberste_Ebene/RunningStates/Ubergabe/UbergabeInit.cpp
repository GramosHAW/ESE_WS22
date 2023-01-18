/*
 * UbergabeInit.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "UbergabeInit.h"
#include "WaitUebergabe.h"
#include "DuMushi.h"
#include "../../../SubEnd.h"

void UbergabeInit::entry(){
}

void UbergabeInit::exit(){

}

void UbergabeInit::showState(){
	cout << "  subsubstateUbergabe: UbergabeInit" << endl;
}

bool UbergabeInit::LS_ENDE_BLOCK(){
	exit();
	new(this) DuMushi;
	entry();
	return true;
}

bool UbergabeInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

