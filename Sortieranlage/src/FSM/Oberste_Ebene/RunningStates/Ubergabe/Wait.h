/*
 * Wait.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_WAIT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_WAIT_H_

#include "../../../BaseState.h"

class Wait: public BaseState {
	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI_SA2() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_WAIT_H_ */
