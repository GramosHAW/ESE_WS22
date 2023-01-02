/*
 * ADC.h
 *
 *  Created on: 14.04.2022
 *      Author: Andrei
 */
#ifndef SRC_HAL_ADCREADER_H_
#define SRC_HAL_ADCREADER_H_

#include <stdio.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <sys/mman.h>
#include <hw/inout.h>
#include <iostream>
#include <thread>
#include <chrono>


#include "ADC_Sources/TSCADC.h"
#include "ADC_Sources/ADC.h"
#include "../Sortieranlage.h"
/*
#include "simqnxgpioapi.h"
#include "simqnxirqapi.h"
#include "../simulation/simulationadapterqnx/simqnxgpioapi.h"
*/

/* Interrupt numbers  (spruh73l.pdf S.465 ff.) */
#define INTER_ADC 16

/* GPIO port addresses (spruh73l.pdf S.177 ff.) */
#define ADC_BASE 0x44E0D000

/* GPIO port registers length */
#define GPIO_REGISTER_LENGHT 0x1000
#define ADC_LENGTH 0x2000

/* TSC_ADC register offsets (spruh73l.pdf S.1747) */
#define ADC_IRQ_ENABLE_SET 0x2c
#define ADC_IRQ_ENABLE_CLR 0x30
#define ADC_IRQ_STATUS 0x28
#define ADC_CTRL 0x40
#define ADC_DATA 0x100

/* ADC irq pin mask */
#define ADC_IRQ_PIN_MASK 0x2

/* GPIO port registers length */
#define ADC_LENGTH 0x2000

/* My pulse codes */
#define PULSE_STOP_THREAD _PULSE_CODE_MINAVAIL + 1
#define PULSE_ADC_SAMLING_DONE _PULSE_CODE_MINAVAIL + 2

/* Code configuration */
#define DEMO true			//true for demo time, false to spin forever.
#define DEMO_DURATION 120		//Duration of demo time in minutes.

class ADCreader{
public:
	ADCreader();
	virtual ~ADCreader();
	void receivingRoutine();
	void startthread();
	int getreciveID();

	/* Variables */

public:
	bool receivingRunning = false;
	int mejurment[200];
	int chanID;
	int conID;
	int reciveID;
private:
	void calibrate_Bandhight();
	TSCADC tsc;
	ADC* adc;
	int bandHight;
//	std::thread& receivingThread;
};

#endif /* SRC_HAL_ADC_ */
