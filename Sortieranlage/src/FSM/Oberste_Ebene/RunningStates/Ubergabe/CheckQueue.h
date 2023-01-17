/*
 * CheckQueue.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_CHECKQUEUE_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_CHECKQUEUE_H_

#include "../../../BaseState.h"

class CheckQueue: public BaseState {
public:
	void entry() override;
	void exit() override;

	void checkQueue();

	void showState() override;

};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_CHECKQUEUE_H_ */
