/*
 * WSWError.cpp
 *
 *  Created on: 29.12.2022
 *      Author: 2nerd
 */

#include "WSWError.h"
#include "../SubEnd.h"
#include "WSWaechter.h"

bool WSWError::FEHLER_BEHOBEN(){
	if(true){
		exit();
		new(this) WSWaechter;
		entry();
		entryHistory();
		return true;
	} else {
		exit();
		new(this) SubEnd;
		entry();
		return true;
	}
}

void WSWError::showState(){
	cout << "State: WSWError" << endl;
}


