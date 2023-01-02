/*
 * ADC.cpp
 *
 *  Created on: 14.04.2022
 *      Author: Andrei
 */

#include "ADCreader.h"
#include "../Dispatcher/Dispatcher.h"
#include "../Events.h"

using namespace std;
using namespace std::chrono;

ADCreader::ADCreader() {
	/* ### Create channel ### */
	chanID = ChannelCreate(0); //Create channel to receive interrupt pulse messages.
	if (chanID < 0) {
		perror("Could not create a channel!\n");
	}
	conID = ConnectAttach(0, 0, chanID, _NTO_SIDE_CHANNEL, 0); //Connect to channel.

	if (conID < 0) {
		perror("Could not connect to channel!");
	}

	//Chanel from Dispacher
	this->reciveID = ChannelCreate(0);

	//printf("ADC new\n");
	adc = new ADC(tsc);

	adc->registerAdcISR(conID, PULSE_ADC_SAMLING_DONE);

	adc->sample();
}
;

ADCreader::~ADCreader() {
	/* ### Cleaning up ### */
	// Detach interrupts.
	adc->adcDisable();
	adc->unregisterAdcISR();
	//Close channel
	int detach_status = ConnectDetach(conID);
	if (detach_status != EOK) {
		perror("Detaching channel failed!");
		exit(EXIT_FAILURE);
	}

	int destroy_status = ChannelDestroy(chanID);
	if (destroy_status != EOK) {
		perror("Destroying channel failed!");
		exit(EXIT_FAILURE);
	}
	//Stop receiving thread.
	MsgSendPulse(conID, -1, PULSE_STOP_THREAD, 0); //using prio of calling thread.
}
;

void ADCreader::startthread() {
	thread receivingThread(&ADCreader::receivingRoutine, this);
	receivingThread.detach();
}
;

void ADCreader::receivingRoutine() {

	ThreadCtl( _NTO_TCTL_IO, 0);	//Request IO privileges for this thread.

	//Chanel to dipascher
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	int connectionIdDispacher = ConnectAttach(0, 0, dispatcher->getchid(),
	_NTO_SIDE_CHANNEL, 0);

	_pulse msg;
	receivingRunning = true;
	bool mejurStarted = false;
	int mejurmentNumber = 0;
	this->bandHight = 4000;

	thread caliThread(&ADCreader::calibrate_Bandhight, this);
	caliThread.detach();

	printf("Message thread started.\n");

	while (receivingRunning) {
		//Interups from ADC hoensensor
		int recvid = MsgReceivePulse(chanID, &msg, sizeof(_pulse), nullptr);
		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.
			//Stop thread while it blocks.
			if (msg.code == PSMG_INTERRUPT) {
				printf("Thread kill code received!\n");
				receivingRunning = false;
				continue;
			}

			if (msg.value.sival_int > bandHight) {

				if (!mejurStarted) {
					MsgSendPulse(connectionIdDispacher,
					SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_HM_START, 0);
					mejurStarted = true;
				}
				mejurmentNumber++;
				MsgSendPulse(connectionIdDispacher,
				SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_HM_DATA, msg.value.sival_int);
			} else if (mejurStarted && (mejurmentNumber >= 180)) {
				mejurStarted = false;
				mejurmentNumber = 0;
				MsgSendPulse(connectionIdDispacher,
				SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_HM_STOP, 0);
			}
			//ADC interrupt value.
			if (msg.code == PULSE_ADC_SAMLING_DONE) {

				//printf("Value from adc with value %d mm\n",msg.value.sival_int);
//				mejurment.add
				adc->sample();
			}

			// Do not ignore OS pulses!
		}
	}

	printf("Message thread stops...\n");
}

void ADCreader::calibrate_Bandhight() {
	_pulse recivemsg;
	//Chanel from Dispacher
	MsgReceivePulse(reciveID, &recivemsg, sizeof(_pulse), nullptr);

	if (recivemsg.code == PSMG_SW_HM_SETWERT) {
		printf("I am set!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		this->bandHight = recivemsg.value.sival_int;
	}
}

int ADCreader::getreciveID() {
	return reciveID;
}
