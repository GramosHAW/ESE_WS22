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

void ContextData::showFlags(){
	cout << "EStop Flag:" << estopp_true << endl;
}

ContextData::werkstueck* ContextData::create_new_werckstuck(){
	return (new werkstueck);
}
