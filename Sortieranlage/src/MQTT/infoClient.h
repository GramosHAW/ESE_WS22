/*
 * infoClient.h
 *
 *  Created on: 18.01.2023
 *      Author: Admin
 */

#ifndef MQTT_INFOCLIENT_H_
#define MQTT_INFOCLIENT_H_

#include "../MQTTpaho/MQTTClient.h"

class infoClient {
private:
	MQTTClient mqtt_cl;
	const char* clientID;

public:
	infoClient(MQTTClient client, const char* client_id);
	virtual ~infoClient();
	MQTTClient& getMQTTClient();
	const char* getClientID();
};

#endif /* MQTT_INFOCLIENT_H_ */
