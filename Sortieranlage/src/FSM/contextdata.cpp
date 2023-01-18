/*
 * contextdata.cpp
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#include "contextdata.h"


using namespace std;
#define BROKER_ADR "tcp://test.mosquitto.org:1883" // Kramus


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

json ContextData::createJSON(int id, Werkstucktup type, int meanheight, int heightSA2) {


	j["team"] = 1.2;
	j["id"] = id;
	j["type"] = type;
	j["meanheight"] = meanheight;
	j["heightSA2"] = heightSA2;
	return j;
}

void ContextData::sendJSON() {
	const char* topic = "FESTO";
		MQTTClient mqttClient;
		mqttClient = new MQTTClient();
		infoClient* info_client = new infoClient(mqttClient, "lappytoppy");
		MQTT_client* cl = new MQTT_client(BROKER_ADR);

		cl->publish(*info_client, topic, createJSON(j.at("id"),j.at("type"), j.at("meanheight"), j.at("heightSA2")));
}


