/*
 * Running.h
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNING_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNING_H_

#include "../BaseState.h"

class Running : public BaseState {
	bool BAND_FREI() override;

	void showState() override;
	void entry() override;
	void exit() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_H_ */
