/*
 * UebergangWSW.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_UEBERGANGWSW_H_
#define SRC_FSM_WSW_UEBERGANGWSW_H_

#include "../BaseState.h"

class UebergangWSW: public BaseState {
	bool WSW_OK() override;

	void showState() override;
};

#endif /* SRC_FSM_WSW_UEBERGANGWSW_H_ */
