/*
 * NeuesWerkstuck.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Borat
 */
#include "NeuesWsIdle.h"
#include "../NeuesWerkstuck/AddNeuesWs.h"

void AddNeuesWs::entry() {
	showState();
	//TODO addqueue, createWSW
	exit();
	new (this) NeuesWsIdle;
	entry();
}
void AddNeuesWs::exit() {

}

void AddNeuesWs::showState(){
	cout << " subsubstateNeuesWerckstuck: NeuesWerkstuck" << endl;
}

