/*
 * SA1.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SA1_H_
#define SRC_FSM_OBERSTE_EBENE_SA1_H_

#include "../BaseState.h"


class SA1 : public BaseState {
public:

	void entry() override;
	void exit() override;
	void entryStartNode() override;

	bool TST_START_KURZ() override;
	bool TST_START_LANG() override;
	bool TST_STOP_KURZ() override;
	bool LS_SORT_BLOCK() override;
	bool SERVICE() override;
	bool BETRIEB() override;
	bool RUHE() override;
	bool ESTOPP_TRUE_SA1() override;
	bool ESTOPP_TRUE_SA2() override;
	bool LS_START_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;
	bool BAND_FREI() override;
	bool BAND_STATUS() override;
	bool HM_START() override;
	bool HM_STOP() override;
	bool ELMNT_DURCH() override;
	bool RUTSCHE_FREI() override;
	bool LS_SORT_FREI() override;
	bool FEHLER_TRUE() override;
	bool FEHLER_SA1() override;
	bool FEHLER_SA2() override;


	void showState() override;
};


#endif /* SRC_FSM_OBERSTE_EBENE_SA1_H_ */
