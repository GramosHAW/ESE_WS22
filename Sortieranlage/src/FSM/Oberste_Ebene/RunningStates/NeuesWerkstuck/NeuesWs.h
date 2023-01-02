/*
 * NeuesWs.h
 *
 *  Created on: 20 Dec 2022
 *      Author: The Boss Man
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWS_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWS_H_

#include "../../../BaseState.h"

class NeuesWs: public BaseState {
public:
	void entry() override;
	void exit() override;
	void showState() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_NEUESWS_H_ */
