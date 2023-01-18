/*
 * contextdata.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#include "contextdata.h"


using namespace std;
using json = nlohmann::json;


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

void ContextData::setuebergabeSendFlag(bool flag){
	this->uebergabeSendFlag = flag;
}

ContextData::werkstueck* ContextData::create_new_werckstuck() {
	return (new werkstueck);
}

void ContextData::createJSON(int id, Werkstucktup type, int meanheight, int heightSA2) {

	json j;
	j["team"] = 1.2;
	j["id"] = id;
	j["type"] = type;
	j["meanheight"] = meanheight;
	j["heightSA2"] = heightSA2;
}
