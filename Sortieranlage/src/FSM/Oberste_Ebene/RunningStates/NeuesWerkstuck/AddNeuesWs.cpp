/*
 * NeuesWerkstuck.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Borat
 */
#include "NeuesWsIdle.h"
#include "../NeuesWerkstuck/AddNeuesWs.h"
#include "../../../contextdata.h"

void AddNeuesWs::entry() {
	//showState();
	addtoQueue();
	exit();
	new (this) NeuesWsIdle;
	entry();
}
void AddNeuesWs::exit() {

}

void AddNeuesWs::showState(){
	cout << " subsubstateNeuesWerckstuck: NeuesWerkstuck" << endl;
}

void AddNeuesWs::addtoQueue() {
	cout << " AddNeuesWs added new" << endl;
	data->Q1.push(new ContextData::werkstueck);
}

