/*
 * IdleFlipped.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_IDLEFLIPPED_H_
#define SRC_FSM_WARNUNG_IDLEFLIPPED_H_

#include "../BaseState.h"

class IdleFlipped: public BaseState {
	bool WS_FLIPPED() override;
	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_IDLEFLIPPED_H_ */
