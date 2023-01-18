/*
 * Betrieb.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_BETRIEB_H_
#define SRC_FSM_OBERSTE_EBENE_BETRIEB_H_

#include "../BaseState.h"

class Betrieb: public BaseState {
	void entryStartNode() override;

	bool TST_STOP_KURZ() override;
	bool LS_START_BLOCK() override;
	bool LS_SORT_FREI() override;
	bool LS_RUTSCHE_FREI() override;
	bool LS_ENDE_BLOCK() override;
	bool LS_ENDE_FREI() override;
	bool ELMNT_AUSSORT() override;
	bool ELMNT_DURCH() override;

	bool BAND_FREI_SA2() override;
	bool LS_START_BLOCK_SA2() override;
	bool LS_ENDE_FREI_SA2() override;

	bool BAND_FREI() override;
	bool RUHE() override;
	bool BAND_STATUS() override;
	//bool BAND_STOP() override;

	bool LS_SORT_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;
	void showState() override;

	//Hoenmesser
	bool HM_START() override;
	bool HM_STOP() override;
	bool HM_DATA(int data) override;

	//Metalsensor
	bool MSENS_METALL() override;

	void entry() override;
	void exit() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_BETRIEB_H_ */
