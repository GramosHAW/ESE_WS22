/*
 * Durchlassen.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_DURCHLASSEN_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_DURCHLASSEN_H_

#include "../../../BaseState.h"

class Durchlassen: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool LS_SORT_FREI() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_DURCHLASSEN_H_ */
