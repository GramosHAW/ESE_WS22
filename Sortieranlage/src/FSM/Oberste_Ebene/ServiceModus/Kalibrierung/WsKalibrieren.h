/*
 * WsKalibrieren.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_WSKALIBRIEREN_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_WSKALIBRIEREN_H_

#include "../../../BaseState.h"

class WsKalibrieren : public BaseState {

	void showState() override;
	void entry() override;
	void exit() override;
	bool TST_START_KURZ() override;
};


#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_WSKALIBRIEREN_H_ */
