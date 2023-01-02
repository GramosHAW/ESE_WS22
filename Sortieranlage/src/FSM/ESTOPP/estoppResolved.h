/*
 * estoppResolved.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_ESTOPP_ESTOPPRESOLVED_H_
#define SRC_FSM_ESTOPP_ESTOPPRESOLVED_H_

#include "../BaseState.h"
#include "ESTOPP.h"

class estoppResolved : public BaseState {
	// void entry() override;
	// ESTOPP OK PMSG
	void entry() override;
	void exit() override;
	void setFlagEStopp(bool);

	bool ESTOPP_OK() override;
	bool ESTOPP_OK_SA2() override;
	bool ESTOPP_TRUE_SA1() override;
	bool ESTOPP_TRUE_SA2() override;
	bool TST_RESET_KURZ() override;
	bool TST_START_KURZ();
	void showState() override;

};



#endif /* SRC_FSM_ESTOPP_ESTOPPRESOLVED_H_ */
