/*
 * Ausortieren.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_AUSORTIEREN_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_AUSORTIEREN_H_

#include "../../../BaseState.h"

class Ausortieren: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;
	void initSubState() override;

	void entryStartNode() override;

	bool BAND_FREI() override;
	bool LS_SORT_BLOCK() override;
	bool LS_SORT_FREI() override;
	bool ELMNT_AUSSORT() override;
	bool ELMNT_DURCH() override;
	bool LS_RUTSCHE_FREI() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_AUSORTIEREN_H_ */
