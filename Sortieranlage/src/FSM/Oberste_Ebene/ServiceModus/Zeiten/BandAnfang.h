/*
 * BandAnfang.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_BANDANFANG_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_BANDANFANG_H_

#include "../../../BaseState.h"

class BandAnfang : public BaseState {

	void entry() override;
	void exit() override;
	void showState() override;
	//bool TST_RESET_KURZ() override;
	bool HM_START() override;
};


#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_BANDANFANG_H_ */
