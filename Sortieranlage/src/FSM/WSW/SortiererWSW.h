/*
 * SortiererWSW.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_SORTIERERWSW_H_
#define SRC_FSM_WSW_SORTIERERWSW_H_

#include "../BaseState.h"

class SortiererWSW : public BaseState {
	bool LS_ENDE_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;

	void showState() override;
};

#endif /* SRC_FSM_WSW_SORTIERERWSW_H_ */
