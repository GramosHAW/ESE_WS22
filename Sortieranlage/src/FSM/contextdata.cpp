/*
 * contextdata.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#include "contextdata.h"
#include <iostream>

using namespace std;

void ContextData::setFlagEStopp(bool flag) {
	this->estopp_true = flag;
}

void ContextData::showFlags() {
	cout << "EStop Flag:" << estopp_true << endl;
}

void ContextData::setrutsche_voll1(bool seter) {
	this->rutsche_voll1 = seter;
}

void ContextData::setrutsche_voll2(bool seter) {
	this->rutsche_voll2 = seter;
}

ContextData::werkstueck* ContextData::create_new_werckstuck() {
	return (new werkstueck);
}
