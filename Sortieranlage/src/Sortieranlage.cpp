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
#include "Reihenfolge.h"
#include "FSM/Oberste_Ebene/ServiceModus/DateiEinlesen.h"
#include <fstream>
#include "FSM\Oberste_Ebene\ServiceModus\DateiEinlesen.h"


//#include "HAL/ADCreader.h"
#include "./Dispatcher/ExternDispatcher.h"
#include "HAL/SimulatedADC.h"
#include "Events.h"
#include "simstarterqnx.h"
#include "simqnxirqapi.h"
#include "simqnxgpioapi.h" // must be last include !!!


//#ifndef RUN_TESTS

using namespace std::chrono;

Sortieranlage::Sortieranlage() {

}
;

Sortieranlage::~Sortieranlage() {

}
;



int main(int argc, char *argv[]) {
	SimulatedADC* simADC = new SimulatedADC();
	simADC->startthread();
	//ADCreader adcreader;
	Sortieranlage sortiranlage;
	Context* context = new Context();

	Dispatcher* dispatcher = Dispatcher::GetInstance();
	dispatcher->set_FSM_chid(context->getChannelID());
	InterruptHandler* irh = InterruptHandler::GetInstance();
	Aktorik* akt = Aktorik::GetInstance();
	ExternDispatcher* externDispatcher = new ExternDispatcher();
	dispatcher->set_Extern_Ch_Id(externDispatcher->getchid());
	std::thread externDispatcherThread(&ExternDispatcher::startThread,externDispatcher);

	context->start_FSM_PulsResiver_THREAD();
	dispatcher->start_HAL_PulsResiver_THREAD();
	//dispatcher->set_ADC_chID(adcreader.getreciveID());TODO
	irh->start_ISR_THREAD();
	akt->start_aktorik_PulsResiver_THREAD();
	//adcreader.startthread();

	simulationStarter->startSimulation();

	DateiEinlesen* dt = new DateiEinlesen;
	dt->setReihenfolge("Reihenfolge.txt");

	//Reihenfolge* rf = new Reihenfolge;
	//rf->setReihenfolge('f','m','h', "Reihenfolge.txt");
	//rf->readDatei("Reihenfolge.txt");
	//rf->getQueue();
	//DateiEinlesen* dt = new DateiEinlesen;
//	dt->setReihenfolge('f', 'h', 'l', "Reihefolge.txt");



	while (1) {
	}
	return 0;
}
;

//#endif
