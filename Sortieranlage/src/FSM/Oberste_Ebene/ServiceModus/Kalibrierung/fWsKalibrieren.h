/*
 * fWsKalibrieren.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_FWSKALIBRIEREN_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_FWSKALIBRIEREN_H_

#include "../../../BaseState.h"


class fWsKalibrieren : public BaseState {

	void showState() override;
	void entry() override;
	void exit() override;
	bool TST_START_KURZ() override;
	//bool TST_RESET_KURZ() override;
	//void BAND_START() override;
	//TODO void msgReceivePulse();
	//TODO fWsEinstellen();
};




#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_FWSKALIBRIEREN_H_ */
