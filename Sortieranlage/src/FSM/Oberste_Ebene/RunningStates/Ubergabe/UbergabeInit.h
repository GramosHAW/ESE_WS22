/*
 * UbergabeInit.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_UBERGABEINIT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_UBERGABEINIT_H_

#include "../../../BaseState.h"

class UbergabeInit: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI() override;
	bool LS_ENDE_BLOCK() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_UBERGABEINIT_H_ */
