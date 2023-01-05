/*
 * RutscheInit.h
 *
 *  Created on: 27 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHEINIT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHEINIT_H_

#include "../../../BaseState.h"

class RutscheInit: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI() override;
	bool LS_RUTSCHE_BLOCK() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHEINIT_H_ */
