/*
 * DateiEinlesen.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "DateiEinlesen.h"

void DateiEinlesen::entry() {
	// tyoeDataRead();
	this->showState();
}


// TODO
void DateiEinlesen::timeOut() {
	//TODO timeout after 10s, when no data read
}

void DateiEinlesen::showState() {
	cout << " <SubState> DateiEinlesen " << endl;
}
