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
//	ThreadPool* newthrewdpool = new ThreadPool();
//	Sortieranlage::threadpool = new ThreadPool;
//	adcreader.startthread();
	//ExternDispatcher* externDispatcher = new ExternDispatcher();
	//externDispatcher->startThread();
//	ImpulsHandler* impulsHandler = new ImpulsHandler();
	/*printf("Creating extern Dispatcher..\n");
	ExternDispatcher* externDispatcher = new ExternDispatcher();
	printf("Extern Dispatcher has been created..\n");
	externDispatcher->startThread();
while (1){}*/
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	dispatcher->set_FSM_chid(context->getChannelID());
	InterruptHandler* irh = InterruptHandler::GetInstance();
    Aktorik* akt = Aktorik::GetInstance();

    context->start_FSM_PulsResiver_THREAD();
	dispatcher->start_HAL_PulsResiver_THREAD();
	irh->start_ISR_THREAD();
	akt->start_aktorik_PulsResiver_THREAD();

    //std::thread threadAmpel(akt->ampelThread, 1000, 2);


	adcreader.startthread();

	while(1){




//		uint32_t impulseResponse = in32(gpio_bank_0 + 0x138);
//		printf("intresp %d\n",impulseResponse>>3&1);




	}
	return 0;
};

//#endif
