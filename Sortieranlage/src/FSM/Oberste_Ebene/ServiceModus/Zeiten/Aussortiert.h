/*
 * Aussortiert.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_AUSSORTIERT_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_AUSSORTIERT_H_

#include "../../../BaseState.h"

class Aussortiert : public BaseState {
	void entry() override;
	void exit() override;
	void showState() override;
	//bool WSW_OK() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_AUSSORTIERT_H_ */
