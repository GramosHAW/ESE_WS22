/*
 * BandAnfang.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "BandAnfang.h"

#include "Hoehenmesser.h"

void BandAnfang::entry() {
	cout << "TEST" << endl;
	this->showState();
}
void BandAnfang::exit() {
}
bool BandAnfang::HM_START() {
	exit();
	new (this) Hoehenmesser;
	entry();
	return true;
}

void BandAnfang::showState() {
	cout << " >> >> >> BandAnfang " << endl;

}



