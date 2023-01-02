/*
 * SA1.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SA1_H_
#define SRC_FSM_OBERSTE_EBENE_SA1_H_

#include "../basestate.h"


class SA1 : public BaseState {
public:
	void entryStartNode() override;

	bool TST_START_KURZ() override;
	bool TST_START_LANG() override;
	bool TST_STOP_KURZ() override;

	bool LS_START_BLOCK() override;
	bool BAND_FREI() override;

	void showState() override;
};


#endif /* SRC_FSM_OBERSTE_EBENE_SA1_H_ */
