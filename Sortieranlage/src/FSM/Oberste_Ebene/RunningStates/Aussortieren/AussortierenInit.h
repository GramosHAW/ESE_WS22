/*
 * AussortierenInit.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_AUSSORTIERENINIT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_AUSSORTIERENINIT_H_

#include "../../../BaseState.h"

class AussortierenInit: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool LS_SORT_BLOCK() override;
	bool BAND_FREI() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_AUSSORTIERENINIT_H_ */
