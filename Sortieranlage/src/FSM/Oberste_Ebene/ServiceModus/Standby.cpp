/*
 * Standby.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "Standby.h"
#include "Service.h"
#include "CheckSA2.h"
#include "../../SubEnd.h"
#include "Kalibrierung/Kalibrierung.h"

void Standby::entry() {
	cout << " >> standby entry " << endl;
	this->showState();
}

//void Standby::initSubState(){
//
//}


// STÜRZT KOMISCHER WEISER BEI RESET NICHT AB, (VLLT WEIL NICHT IN SA1 DRIN, SA1::TST_RESET_KURZ() nicht existent
bool Standby::TST_RESET_KURZ() {
	//exit();
	new (this) DateiEinlesen;
	entry();
	return true;
}

bool Standby::TST_START_KURZ() {
	//exit();
	cout << " >> in Standby [start] gedrückt" << endl;
	new (this) Kalibrierung;
	entry();
	entryStartNode();
	return true;

}

bool Standby::TST_STOP_KURZ() {
	// RAUS TRANSITION
	exit();
	new (this) SubEnd;
	entry();
	return true;
}

bool Standby::TST_START_LANG() {
	exit();
	new (this) CheckSA2;
	entry();
	return true;
}

void Standby::showState() {
	cout << " <SubState> Standby " << endl;
	//substateSERV->showState();
}
