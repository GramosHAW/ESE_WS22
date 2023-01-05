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
	void entry() override;
	void exit() override;

	bool ESTOPP_TRUE_SA1() override;
	bool ESTOPP_TRUE_SA2() override;
	bool TST_RESET_KURZ() override;
	bool ESTOPP_QUIT() override;

	void showState() override;
};



#endif /* SRC_FSM_ESTOPP_ESTOPPRESET_H_ */
