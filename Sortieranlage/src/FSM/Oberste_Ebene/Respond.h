/*
 * Respond.h
 *
 *  Created on: 03.01.2023
 *      Author: 2nerd
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RESPOND_H_
#define SRC_FSM_OBERSTE_EBENE_RESPOND_H_

#include "../BaseState.h"

class Respond: public BaseState {
public:
	void entry() override;

	bool LS_START_BLOCK() override;

	void showState() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RESPOND_H_ */
