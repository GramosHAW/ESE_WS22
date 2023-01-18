/*
 * infoClient.cpp
 *
 *  Created on: 18.01.2023
 *      Author: Admin
 */

#include "infoClient.h"

infoClient::infoClient(MQTTClient client, const char* client_id) {
	mqtt_cl = client;
	clientID = client_id;
}

const char* infoClient::getClientID() {
	return clientID;
}

MQTTClient& infoClient::getMQTTClient() {
	return mqtt_cl;
}

infoClient::~infoClient() {
	// TODO Auto-generated destructor stub
}

