/*
 * Aktorik.h
 *
 *  Created on: 01.05.2022
 *      Author: Muschi
 */


#ifndef IMPULSHANDELR_H_
#define IMPULSHANDELR_H_

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <sys/neutrino.h>
//#include <mutex>
//#include <thread>
#include "../Dispatcher/Dispatcher.h"


class ImpulsHandler{
private:
	std::thread *isr_thread;
	int fsmChannelId;
	bool run_thread;
	int dispatcherChanel;
	void handelFSMpuls();
	void calculateHigt();
	int mejurments[200];

	enum Werk{
		flach,
		hoch,
		loch,
		metal,
		undefined
	};

	Werk werkstucktup;

public:
	ImpulsHandler();
	virtual ~ImpulsHandler();
	void start_FSM_PulsResiver_THREAD(void);
	int getchid();

};
#endif
