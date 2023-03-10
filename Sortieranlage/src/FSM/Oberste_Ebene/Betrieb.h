/*
 * Betrieb.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_BETRIEB_H_
#define SRC_FSM_OBERSTE_EBENE_BETRIEB_H_

#include "../BaseState.h"

class Betrieb : public BaseState {
	void entryStartNode() override;

	bool TST_STOP_KURZ() override;
	bool LS_START_BLOCK() override;
	bool BAND_FREI() override;
	//bool BAND_STOP() override;

	bool LS_SORT_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;
	void showState() override;

	void entry() override;
	void exit() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_BETRIEB_H_ */
