/*
 * contextdata.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#include <iostream>
#include "contextdata.h"

using namespace std;

ContextData::ContextData() {
	chID_disp = -1;
	band_hoehe = 0;
	mittelwert = 0;
	estopp = false;
	anderer_estopp = false;
	estopp_flag = false;
	rutsche_voll = false;
	andere_rutsche_voll = false;
	auswerfer = false;
	weiche = false;

	ND_flag = false;
	NA_flag = false;
	LD_flag = false;
	LA_flag = false;

}

ContextData::~ContextData() {}


void ContextData::setBandHoehe(int band_hoehe) {
	this->band_hoehe = band_hoehe;
}

int ContextData::getBandHoehe() {
	return band_hoehe;
}

void ContextData::sortEinstellen(char sortiereinheit) {
	if (sortiereinheit == 'A') {
		auswerfer = true;
	}
	else if (sortiereinheit == 'W') {
		weiche = true;
	}
}

void ContextData::uebergangEinstellen() {
	//TODO
}

void ContextData::setFlagEStopp() {
	estopp_flag = true;
}

bool ContextData::Rutsche1voll() {
	if (rutsche_voll) {return true;}
	else {return false;}
}

void ContextData::setRutsche1voll() {
	// if PMsg_SW_RUTSCHE_VOLL received
	this->rutsche_voll = true;
}


bool ContextData::Rutsche2voll() {
	if (andere_rutsche_voll) {return true;}
	else {return false;}
}

void ContextData::setRutsche2voll() {
	// if PMsg_SW_RUTSCHE_VOLL_SA2 received
	this->andere_rutsche_voll = true;
}

