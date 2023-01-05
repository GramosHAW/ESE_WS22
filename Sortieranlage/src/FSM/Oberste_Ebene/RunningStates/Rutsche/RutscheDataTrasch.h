/*
 * RutscheDataTrasch.h
 *
 *  Created on: 27 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHEDATATRASCH_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHEDATATRASCH_H_

#include "../../../BaseState.h"

class RutscheDataTrasch: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool LS_RUTSCHE_FREI() override;
	bool RUTSCHE_VOLL_SA1() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHEDATATRASCH_H_ */
