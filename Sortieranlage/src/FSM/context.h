/*
 * context.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_CONTEXT_H_
#define SRC_FSM_CONTEXT_H_

#include "actions.h"
#include "basestate.h"
#include "contextdata.h"
#include "../Dispatcher/dispatcher.h"
#include <thread>

class Context {
private:

	BaseState *WSWarray[10];
	BaseState *state;
	BaseState *stateWarnungRutsche;
//BaseState *stateWarnungFlipped;
	Actions *action;
	ContextData data;
	std::thread* dispatcher_thread;
	unsigned char channelID;

public:
	Context(Actions *shared_action);
	Context();
	int getChannelID();
	void start_FSM_PulsResiver_THREAD(void);
	void awaitEvent();
	void newWSW();
	void printarray();
	void initarray();
	virtual ~Context();
};



#endif /* SRC_FSM_CONTEXT_H_ */
