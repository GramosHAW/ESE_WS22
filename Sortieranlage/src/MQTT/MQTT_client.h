/*
 * MQTTBroker.h
 *
 *  Created on: 14.01.2023
 *      Author: Admin
 */

#ifndef MQTT_MQTT_CLIENT_H_
#define MQTT_MQTT_CLIENT_H_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "../MQTTpaho/MQTTclient.h"
#include "json.hpp"
#include "infoClient.h"



using json = nlohmann::json;
//#include <mosquittopp.h>

class MQTT_client{
	//static int disp_coid = -1;
private:
	const char* brokerAddr;

public:

#define ADDRESS 	"tcp://localhost:1883"
#define	CLIENTID 	"TestClient"
#define TOPIC 		"FESTO/"
#define PAYLOAD 	"HELLO WERKSTÜCK"
#define QOS 		1
#define TIMEOUT 	10000L


	MQTT_client(const char*);
	virtual ~MQTT_client();

	int publish(infoClient&, const char*, json);
	void clientConnect();


};

#endif /* MQTT_MQTT_CLIENT_H_ */
