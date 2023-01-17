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

	bool BAND_FREI_SA2() override;
	//Lichtschreank

	bool LS_START_BLOCK_SA2() override;
	bool LS_RUTSCHE_BLOCK() override;
	bool LS_RUTSCHE_FREI() override;
	bool LS_START_BLOCK() override;
	bool LS_SORT_FREI() override;
	bool LS_SORT_BLOCK() override;
	bool LS_ENDE_BLOCK() override;
#ifdef SIM_TWIN_B
	bool LS_ENDE_FREI() override;
#endif
	bool LS_ENDE_FREI_SA2() override;

	bool TST_STOP_KURZ() override;

	//Hoenmesser
	bool HM_START() override;
	bool HM_STOP() override;
	bool HM_DATA(int data) override;

	//Metalsensor
	bool MSENS_METALL() override;
	//bool MSENS_METALL_OHNE() override;

	bool ELMNT_DURCH() override;
	bool ELMNT_AUSSORT() override;

	//bool RUTSCHE_FREI() override;
	//bool RUTSCHE_VOLL_SA1() override;

};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_H_ */
