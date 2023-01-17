/*
 * Rutsche.h
 *
 *  Created on: 27 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHE_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHE_H_

#include "../../../BaseState.h"

class Rutsche: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;
	void initSubState() override;

	void entryStartNode() override;

	bool BAND_FREI() override;
	bool LS_RUTSCHE_BLOCK() override;
	/*
	bool LS_RUTSCHE_FREI() override;
	bool RUTSCHE_VOLL_SA1() override;
	*/
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_RUTSCHE_RUTSCHE_H_ */
