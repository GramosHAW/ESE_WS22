/*
 * estoppReset.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_ESTOPP_ESTOPPRESET_H_
#define SRC_FSM_ESTOPP_ESTOPPRESET_H_

#include "../BaseState.h"

#include "ESTOPP.h"

class estoppReset : public BaseState {
	bool TST_RESET_KURZ() override;
	void entry() override;
	void exit() override;
	bool ESTOPP_FALSE_SA1() override;
	void showState() override;
};



#endif /* SRC_FSM_ESTOPP_ESTOPPRESET_H_ */
