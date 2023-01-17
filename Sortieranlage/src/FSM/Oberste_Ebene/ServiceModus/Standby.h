/*
 * Standby.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_STANDBY_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_STANDBY_H_

#include "../../BaseState.h"
#include "DateiEinlesen.h"

class Standby : public BaseState {

	bool TST_RESET_KURZ() override;
	bool TST_START_KURZ() override;
	bool TST_STOP_KURZ() override;
	bool TST_START_LANG() override;
	bool RUHE() override;
	void showState() override;
	void entry() override;
	void exit() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_STANDBY_H_ */
