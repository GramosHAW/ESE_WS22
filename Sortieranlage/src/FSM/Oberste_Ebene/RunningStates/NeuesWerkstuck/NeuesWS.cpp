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

void NeuesWs::entry(){
	//TODO - createQue, addQue,createWSW
	showState();
	exit();
	new (this) NeuesWsIdle;
	entry();
}

void NeuesWs::exit(){

}

void NeuesWs::showState(){
	cout << " subsubstateNeuesWerckstuck: NeuesWs" << endl;
}

