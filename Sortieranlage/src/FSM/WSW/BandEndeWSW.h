/*
 * BandEnde.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_BANDENDE_H_
#define SRC_FSM_WSW_BANDENDE_H_

#include "../BaseState.h"

class BandEndeWSW: public BaseState {

	bool LS_ENDE_BLOCK_SA2() override;
	bool WSW_OK() override;

	void showState() override;
};

#endif /* SRC_FSM_WSW_BANDENDE_H_ */
