/*
 * estoppStart.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_ESTOPP_ESTOPPSTART_H_
#define SRC_FSM_ESTOPP_ESTOPPSTART_H_

#include "../BaseState.h"
#include "ESTOPP.h"

class estoppStart : public BaseState {
	bool ESTOPP_TRUE_SA1() override;
	bool ESTOPP_FALSE_SA1() override;
	bool ESTOPP_FALSE_SA2() override;
	void showState() override;
	bool TST_RESET_KURZ() override;
	bool TST_START_KURZ() override;
	bool TST_STOP_KURZ() override;

	void entry() override;
	void exit() override;

public:
	bool estopp_flag;
};



#endif /* SRC_FSM_ESTOPP_ESTOPPSTART_H_ */
