/*
 * UbergabeInit.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "UbergabeInit.h"
#include "Wait.h"

void UbergabeInit::entry(){
	showState();
}

void UbergabeInit::exit(){

}

void UbergabeInit::showState(){
	cout << "  subsubstateUbergabe: UbergabeInit" << endl;
}

bool UbergabeInit::LS_ENDE_BLOCK(){
	exit();
	new (this) Wait;
	entry();
	return true;
}
