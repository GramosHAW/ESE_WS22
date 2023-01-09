/*
 * Wait.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_WAIT_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_WAIT_H_

#include "../../BaseState.h"

class Wait : public BaseState {
public:
	bool LS_ENDE_BLOCK() override;
	//void showState() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_WAIT_H_ */
