/*
 * Sortierer.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_SORTIERER_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_SORTIERER_H_

#include "../../../BaseState.h"

class Sortierer : public BaseState {
	void entry() override;
	void exit() override;
	void showState() override;
	bool LS_ENDE_BLOCK() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_SORTIERER_H_ */
