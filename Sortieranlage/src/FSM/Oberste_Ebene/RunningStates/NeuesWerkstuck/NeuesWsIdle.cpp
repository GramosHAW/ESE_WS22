/*
 * NeuesWsIdle.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Borat
 */
#include "NeuesWsIdle.h"
#include "AddNeuesWs.h"
#include "../../../SubEnd.h"

bool NeuesWsIdle::LS_START_BLOCK() {
	cout << " Start BLOCK in NeuesWsIdle!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	exit();
	new (this) AddNeuesWs;
	entry();
	return true;
}

bool NeuesWsIdle::BAND_FREI() {
	exit();
	new(this) SubEnd;
	entry();
	return true;
}

void NeuesWsIdle::entry() {
	showState();
}

void NeuesWsIdle::exit() {
}

void NeuesWsIdle::showState(){
	cout << " subsubstateNeuesWerckstuck: NeuesWsIdle" << endl;
}
