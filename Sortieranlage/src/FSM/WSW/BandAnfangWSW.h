/*
 * BandAnfang.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_BANDANFANGWSW_H_
#define SRC_FSM_WSW_BANDANFANGWSW_H_

#include "../BaseState.h"

class BandAnfangWSW : public BaseState {

	bool HM_START() override;

	void showState() override;
};

#endif /* SRC_FSM_WSW_BANDANFANGWSW_H_ */
