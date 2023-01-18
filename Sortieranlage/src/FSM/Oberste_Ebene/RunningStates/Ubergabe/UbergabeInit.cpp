/*
 * UbergabeInit.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "UbergabeInit.h"
#include "Wait.h"
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
	printf("I am Hiere !!!!!!!!!!!!!!!!!!!\n");
	this->showState();
	new (this) Wait;
	printf("I am Hiere !!!!!!!!!!!!!!!!!!!\n");
	this->showState();
	entry();
	return true;
}

bool UbergabeInit::BAND_FREI() {
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

