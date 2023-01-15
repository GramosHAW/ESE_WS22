/*
 * MQTTBroker.cpp
 *
 *  Created on: 14.01.2023
 *      Author: Admin
 */


#include "MQTT_client.h"


//MQTT_Broker::MQTTBroker() {
//	// TODO Auto-generated constructor stub
//
//}
//
//MQTT_Broker::~MQTTBroker() {
//	// TODO Auto-generated destructor stub
//}

void MQTT_Client::clientConnect() {


}

int MQTT_Client::publish() {



	printf("Running simple MQTT client publish example ");
	fflush (stdout);
	MQTTClient client;
	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	MQTTClient_message pubmsg = MQTTClient_message_initializer;
	MQTTClient_deliveryToken token;
	int rc;

	if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
			MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS) {
		printf("Failed to create client, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}

	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 0;
	if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
		printf("Failed to connect, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}

	char payload[20] = "Hello World!";
	pubmsg.payload = payload;
	pubmsg.payloadlen = (int) strlen(payload);
	pubmsg.qos = QOS;
	pubmsg.retained = 0;
	if ((rc = MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token))
			!= MQTTCLIENT_SUCCESS) {
		printf("Failed to publish message, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}

	printf("Waiting for up to %d seconds for publication of %s\n"
			"on topic %s for client with ClientID: %s\n",
			(int) (TIMEOUT / 1000), PAYLOAD, TOPIC, CLIENTID);
	rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
	printf("Message with delivery token %d delivered\n", token);

	if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
		printf("Failed to disconnect, return code %d\n", rc);
	MQTTClient_destroy(&client);
	return rc;



}
