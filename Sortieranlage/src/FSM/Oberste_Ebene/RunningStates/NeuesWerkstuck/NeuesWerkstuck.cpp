/*
 * NeuesWerkstuck.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Borat
 */
#include "NeuesWs.h"
#include "NeuesWerkstuck.h"

void NeuesWerkstuck::initSubState(){
	subsubstateNeuesWerckstuck = new NeuesWs;
}

void NeuesWerkstuck::entryStartNode() {
	initSubState();
	new (subsubstateNeuesWerckstuck) NeuesWs;
	subsubstateNeuesWerckstuck->entry();
}

bool NeuesWerkstuck::LS_START_BLOCK() {
	bool handled = subsubstateNeuesWerckstuck->LS_START_BLOCK();
	return handled;
}
bool NeuesWerkstuck::BAND_FREI() {
	bool handled = subsubstateNeuesWerckstuck->BAND_FREI();
	return handled;
}

void NeuesWerkstuck::entry() {
	showState();
}

void NeuesWerkstuck::exit() {

}

void NeuesWerkstuck::showState(){
	cout << " substateNeuesWerckstuck: NeuesWerkstuck" << endl;
	subsubstateNeuesWerckstuck->showState();
}

