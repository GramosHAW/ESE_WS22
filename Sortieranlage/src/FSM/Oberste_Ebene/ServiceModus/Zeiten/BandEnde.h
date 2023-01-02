/*
 * BandEnde.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_BANDENDE_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_BANDENDE_H_

#include "../../../BaseState.h"

class BandEnde : public BaseState {
	void entry() override;
	void exit() override;
	void showState() override;
	//bool WSW_OK() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_BANDENDE_H_ */
