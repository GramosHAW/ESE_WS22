/* Simple demostration of the simulator usage
 * @author: Ormenisan Andrei
 * @author: Ormenisan Andrei
 * @date: 2022-05-01
 */
#include "HAL/Aktorik.h"
#include "Sortieranlage.h"
#include "HAL/GPIO.h"
#include "HAL/InterruptHandler.h"
#include "Dispatcher/Dispatcher.h"
#include "FSM/ImpulsHandler.h"
#include "FSM/context.h"


#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <sys/mman.h>
#include <hw/inout.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "HAL/ADCreader.h"
#include "./Dispatcher/ExternDispatcher.h"
#include "simqnxirqapi.h"
#include "Events.h"


#include "simqnxgpioapi.h" // must be last include !!!

//#ifndef RUN_TESTS

using namespace std::chrono;

Sortieranlage::Sortieranlage(){
};

Sortieranlage::~Sortieranlage() {

};

int main() {

	ADCreader adcreader;
	Sortieranlage sortiranlage;
	Context* context = new Context();

	Dispatcher* dispatcher = Dispatcher::GetInstance();
	dispatcher->set_FSM_chid(context->getChannelID());
	InterruptHandler* irh = InterruptHandler::GetInstance();
    Aktorik* akt = Aktorik::GetInstance();


    context->start_FSM_PulsResiver_THREAD();
	dispatcher->start_HAL_PulsResiver_THREAD();
	dispatcher->set_ADC_chID(adcreader.getreciveID());
	irh->start_ISR_THREAD();
	akt->start_aktorik_PulsResiver_THREAD();
	adcreader.startthread();


	while(1){
	}
	return 0;
};

//#endif
