/*
 * Aktorik.h
 *
 *  Created on: 14.04.2022
 *      Author: Noel
 */

#ifndef SRC_HAL_AKTORIK_H_
#define SRC_HAL_AKTORIK_H_


//#include "../simulation/simulationadapterqnx/simqnxgpioapi.h"

#include <iostream>
#include <memory>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctime>
#include <chrono>
#include <queue>
#include <cstdio>
#include <mutex>
//Machine
#include <sys/neutrino.h>
#include <hw/inout.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/netmgr.h>
#include <sys/siginfo.h>
#include <sys/dispatch.h>
#include <sys/types.h>




//GPIO shortcuts

#define GPIO_OE					0x134
#define GPIO_SETDATAOUT			0x194
#define GPIO_CLEARDATAOUT		0x190
#define GPIO_IRQSTATUS_CLR_0	0x3C



// Bank 1 GPIOs
#define MOTOR_RECHTSLAUF 	0x1000
#define MOTOR_LINKSLAUF 	0x2000
#define MOTOR_LANGSAM 		0x4000
#define MOTOR_STOP 			0x8000
#define ROTE_LAMPE 			0x10000
#define GELBE_LAMPE 		0x20000
#define GRUENE_LAMPE	 	0x40000
#define WEICHE		 		0x80000

// Used for Blinking funktion
#define GRUEN              0x1
#define GELB               0x2
#define ROT                0x3

class Aktorik{
public:
    int getAktorikId();
    void start_aktorik_PulsResiver_THREAD(void);
//Singleton
    Aktorik(Aktorik &other) = delete;
    void operator=(const Aktorik &) = delete;
    static Aktorik *GetInstance();
    int getchid();
protected:
	Aktorik();
	~Aktorik();
private:
    //Singleton
    static std::mutex mutex_;
    static Aktorik* m_pInstance;

	//Ampel kommands
	void ampelGruenAn();
	void ampelGruenAus();
	void ampelGelbAn();
	void ampelGelbAus();
	void ampelRotAn();
	void ampelRotAus();

	//Motor Kommands
	void motorRechtslaufAn();
	void motorRechtslaufAus();
	void motorLinkslaufAn();
	void motorLinkslaufAus();
	void motorLangsamAn();
	void motorLangsamAus();
	void motorStopAn();
	void motorStopAus();

	//Weichen kommands
	void weicheAuf();
	void weicheZu();

	//Ampel blinken
	void ampelGruenBlinken();
	void ampelRotBlinkenSchnell();
	void ampelRotBlinkenLangsam();
    void ampelThread(int delay, int ampel);

	uintptr_t gpio_bank_1 = mmap_device_io(0x1000, (uint64_t) 0x4804C000);
	//Chanel fure die Pulsmesseges
	int chIdAktorik;
	//Wariabilen fure der handelHalPuls Thread
	bool run_thread;
	std::thread * akt_thread;
	//used to control lamp blinking
	bool run = true;
	std::thread * blink_thread;
	//Swich kase wo die Pulsmesiges verarbeited werden
	void handelHALpuls();
};




#endif /* SRC_HAL_AKTORIK_H_ */
