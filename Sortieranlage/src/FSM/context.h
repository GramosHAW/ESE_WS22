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
#include "../Dispatcher/dispatcher.h"
#include <thread>

class Context {
private:
	BaseState *state;
	Actions *action;
	std::thread* dispatcher_thread;
	unsigned char channelID;
public:
	Context(Actions *shared_action);
	Context();
	int getChannelID();
	void start_FSM_PulsResiver_THREAD(void);
	void awaitEvent();
	virtual ~Context();
};



#endif /* SRC_FSM_CONTEXT_H_ */
