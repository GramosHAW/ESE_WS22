/*
 * NeuesWerkstuck.h
 *
 *  Created on: 17.12.2022
 *      Author: 3nerd
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWERKSTUCK_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWERKSTUCK_H_

#include "../../../BaseState.h"

class NeuesWerkstuck: public BaseState {
public:
	void entryStartNode() override;
	void initSubState() override;

	bool LS_START_BLOCK() override;
	bool BAND_FREI() override;

	void entry() override;
	void exit() override;
	void showState() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWERKSTUCK_H_ */
