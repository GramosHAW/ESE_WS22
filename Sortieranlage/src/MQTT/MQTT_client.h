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


//#include <mosquittopp.h>

class MQTT_Client{
	//static int disp_coid = -1;
private:
	const char* brockerAdr;

public:

#define ADDRESS 	"tcp://localhost:1883"
#define	CLIENTID 	"TestClient"
#define TOPIC 		"WERKSTUECK INFO"
#define PAYLOAD 	"HELLO WERKSTÜCK"
#define QOS 		1
#define TIMEOUT 	10000L


	int publish();
	void clientConnect();


};

#endif /* MQTT_MQTT_CLIENT_H_ */
