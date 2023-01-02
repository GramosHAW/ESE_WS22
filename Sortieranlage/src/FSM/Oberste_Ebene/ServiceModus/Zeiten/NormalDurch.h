/*
 * NormalDurch.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_NORMALDURCH_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_NORMALDURCH_H_

#include "../../../BaseState.h"


class NormalDurch : public BaseState{
	void entry() override;
	void exit() override;
	void showState() override;
	bool TST_RESET_KURZ() override;
	bool ND_Flag();

	bool ndFlag = false;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_NORMALDURCH_H_ */
