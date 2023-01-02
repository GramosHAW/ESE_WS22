/*
 * CheckSA2.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_CHECKSA2_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_CHECKSA2_H_

#include "../../BaseState.h"

class CheckSA2 : public BaseState {

	void entry() override;

	bool TST_STOP_KURZ() override;

	void showState() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_CHECKSA2_H_ */
