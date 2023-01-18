/*
 * MQTTBroker.cpp
 *
 *  Created on: 14.01.2023
 *      Author: Admin
 */


#include "MQTT_client.h"
#include "json.hpp"


MQTT_client::MQTT_client(const char* broker_addr) {
	this->brokerAddr = broker_addr;
}

MQTT_client::~MQTT_client() {

}

void MQTT_client::clientConnect() {


}

int MQTT_client::publish(infoClient& cl, const char *topic, json payload) {

	printf("Running simple MQTT client publish example ");
	fflush (stdout);

	MQTTClient client = cl.getMQTTClient();
	const char* client_id = cl.getClientID();
	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	MQTTClient_message pubmsg = MQTTClient_message_initializer;
	MQTTClient_deliveryToken token;
	int rc;

	if ((rc = MQTTClient_create(&client, brokerAddr, client_id,
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


	pubmsg.payload = &payload;
	pubmsg.payloadlen = sizeof(payload);
	pubmsg.qos = QOS;
	pubmsg.retained = 0;
	if ((rc = MQTTClient_publishMessage(client, topic, &pubmsg, &token))
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
