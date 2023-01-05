/*
 * SimulatedADC.h
 *
 *  Created on: 5 Jan 2023
 *      Author: andre
 */

#ifndef SRC_HAL_SIMULATEDADC_H_
#define SRC_HAL_SIMULATEDADC_H_

#include <stdio.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "simqnxgpioapi.h"
#include "simqnxirqapi.h"

/* Code configuration */
#define DEMO true			//true for demo time, false to spin forever.
#define DEMO_DURATION 3		//Duration of demo time in minutes.

/* Interrupt numbers  (spruh73l.pdf S.465 ff.) */
#define INTER_ADC 16

/* GPIO port addresses (spruh73l.pdf S.177 ff.) */
#define GPIO_PORT0 0x44E07000
#define GPIO_PORT1 0x4804C000
#define GPIO_PORT2 0x481AC000
#define ADC_BASE 0x44E0D000

/* GPIO port registers length */
#define GPIO_REGISTER_LENGHT 0x1000
#define ADC_LENGTH 0x2000

/* GPIO register offsets (spruh73l.pdf S.4877) */
#define GPIO_DATAIN 0x138
#define GPIO_SETDATAOUT 0x194

/* TSC_ADC register offsets (spruh73l.pdf S.1747) */
#define ADC_IRQ_ENABLE_SET 0x2c
#define ADC_IRQ_ENABLE_CLR 0x30
#define ADC_IRQ_STATUS 0x28
#define ADC_CTRL 0x40
#define ADC_DATA 0x100

/* ADC irq pin mask */
#define ADC_IRQ_PIN_MASK 0x2

/* Actuators pin mapping (Aufgabenbeschreibung o. Schaltplan) */
#define MOTOR_RIGHT_PIN 12
#define MOTOR_SLOW_PIN 14

/* My pulse codes */
#define PULSE_STOP_THREAD _PULSE_CODE_MINAVAIL + 1
#define PULSE_ADC_SAMLING_DONE _PULSE_CODE_MINAVAIL + 2

/* Helper macros */
#define BIT_MASK(x) (0x1 << (x))

/* Implementations */
using namespace std;

class SimulatedADC {
public:
	SimulatedADC();
	virtual ~SimulatedADC();
	void startthread();

private:

	/* Variables */
	sigevent event;
	int interruptID;
	uintptr_t adcBaseAddr;
	bool receivingRunning = false;
	int chanID;
	int conID;
	thread receivingThread;

	/* Prototypes */
	const struct sigevent* adcISR(void* arg, int id);

	void receivingRoutine();

	void adc_enable_interrupt(void);
	void adc_disable_interrupt(void);
	void adc_clear_interrupt(void);
	void adc_ctrl_start_sample(void);
	uint32_t adc_read_sample_data(void);

};

#endif /* SRC_HAL_SIMULATEDADC_H_ */
