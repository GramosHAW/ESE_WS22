/*
 * WSUbergeben.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_WSUBERGEBEN_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_WSUBERGEBEN_H_

#include "../../../BaseState.h"

class WSUbergeben: public BaseState {

public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool LS_START_BLOCK_SA2() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_WSUBERGEBEN_H_ */
