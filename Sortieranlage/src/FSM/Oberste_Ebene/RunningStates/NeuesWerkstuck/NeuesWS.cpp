/*
 * NeuesWs.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Der Obermeister
 */
#include "../../BIdle.h"
#include "AddNeuesWs.h"
#include "NeuesWs.h"
#include "NeuesWsIdle.h"
#include "../../../../Queue/ThreadsafeQueue.h"
#include "../../../contextdata.h"

void NeuesWs::entry() {
	addtoQueue();
	exit();
	new (this) NeuesWsIdle;
	entry();
}

void NeuesWs::exit() {

}

void NeuesWs::showState() {
	cout << " subsubstateNeuesWerckstuck: NeuesWs" << endl;
}

void NeuesWs::addtoQueue() {
	cout << " NeuesWs added new" << endl;
#ifdef SIM_TWIN_B
	data->Q1.push(data->ubergebeneWS);
#else
	data->Q1.push(new ContextData::werkstueck);
	data->Q1.front()->id = data->wsID;
	data->wsID += 1;
#endif
}
