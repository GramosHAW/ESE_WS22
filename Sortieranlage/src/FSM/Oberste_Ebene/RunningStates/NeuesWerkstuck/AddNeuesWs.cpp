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
#ifdef SIM_TWIN_B
	data->Q1.push(data->ubergebeneWS);
#else
	data->Q1.push(new ContextData::werkstueck);
	data->Q1.front()->id = data->wsID;
	data->wsID += 1;
#endif
}

