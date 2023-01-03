/*
 * HoehnmesserWSW.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_HOEHNMESSERWSW_H_
#define SRC_FSM_WSW_HOEHNMESSERWSW_H_

#include "../BaseState.h"

class HoehnmesserWSW : public BaseState {

	bool LS_SORT_BLOCK() override;

	void showState() override;
};

#endif /* SRC_FSM_WSW_HOEHNMESSERWSW_H_ */
