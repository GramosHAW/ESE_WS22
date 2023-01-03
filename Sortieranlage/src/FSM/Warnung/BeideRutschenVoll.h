/*
 * BeideRutschenVoll.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_BEIDERUTSCHENVOLL_H_
#define SRC_FSM_WARNUNG_BEIDERUTSCHENVOLL_H_

#include "../BaseState.h"

class BeideRutschenVoll: public BaseState {
	bool ELMNT_AUSSORT() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_BEIDERUTSCHENVOLL_H_ */
