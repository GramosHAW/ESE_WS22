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
	//bool TST_STOP_LANG() override;
	//bool ESTOPP_FALSE_SA1() override;
	bool ESTOPP_TRUE_SA1() override;

	//Lichtschrenke
	bool LS_SORT_FREI() override;
	bool LS_SORT_BLOCK() override;

	bool LS_START_BLOCK_SA2() override;
	bool LS_START_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;
	bool LS_RUTSCHE_FREI() override;
	bool LS_ENDE_BLOCK() override;
	bool LS_ENDE_FREI() override;

	bool BAND_FREI() override;

	//Hoenmesser
	bool HM_START() override;
	bool HM_STOP() override;

	//Metalsensor
	bool MSENS_METALL() override;
	bool MSENS_METALL_OHNE() override;

	bool ELMNT_DURCH() override;
	bool BAND_FREI_SA2() override;
	bool RUTSCHE_FREI() override;
	bool RUTSCHE_VOLL_SA1() override;

	bool ELMNT_AUSSORT() override;

	void showState() override;
};


#endif /* SRC_FSM_OBERSTE_EBENE_SA1_H_ */
