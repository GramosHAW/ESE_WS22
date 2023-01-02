/*
 * NeuesWsIdle.h
 *
 *  Created on: 20 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWSIDLE_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWSIDLE_H_

#include "../../../BaseState.h"

class NeuesWsIdle: public BaseState {
public:
	bool LS_START_BLOCK() override;
	bool BAND_FREI() override;

	void entry() override;
	void exit() override;
	void showState() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWSIDLE_H_ */
