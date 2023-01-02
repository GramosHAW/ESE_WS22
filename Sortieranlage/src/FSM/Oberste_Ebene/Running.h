/*
 * Running.h
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNING_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNING_H_

#include "../BaseState.h"

class Running: public BaseState {
	bool BAND_FREI() override;
	void initSubState() override;

	void showState() override;
	void entry() override;
	void exit() override;

	bool LS_ENDE_BLOCK() override;

	bool LS_RUTSCHE_BLOCK() override;
	bool LS_START_BLOCK() override;
	bool LS_SORT_BLOCK() override;
	bool TST_STOP_KURZ() override;
	bool HM_START() override;
	bool HM_STOP() override;
	bool ELMNT_DURCH() override;
	bool RUTSCHE_FREI() override;
	bool LS_SORT_FREI() override;

};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_H_ */
