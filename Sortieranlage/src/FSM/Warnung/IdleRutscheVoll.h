/*
 * IdleRutscheVoll.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_IDLERUTSCHEVOLL_H_
#define SRC_FSM_WARNUNG_IDLERUTSCHEVOLL_H_

#include "../BaseState.h"

class IdleRutscheVoll: public BaseState {

	void entry() override;

	bool RUTSCHE_VOLL_SA1() override;
	bool RUTSCHE_VOLL_SA2() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_IDLERUTSCHEVOLL_H_ */
