/*
 * ESTOPP.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_ESTOPP_ESTOPP_H_
#define SRC_FSM_ESTOPP_ESTOPP_H_

#include "../BaseState.h"

class ESTOPP : public BaseState {

protected:

public:
	void entry() override;
	void exit() override;
	void showState() override;
	void entryStartNode() override;
	void setFlagEStopp(bool);
//	bool TST_START_KURZ() override;
//	void initSubState() override;

	// ## bool handled ##
	bool ESTOPP_TRUE_SA1() override;
	bool ESTOPP_TRUE_SA2() override;
	bool ESTOPP_FALSE_SA1() override;
	bool ESTOPP_FALSE_SA2() override;
	bool ESTOPP_OK_SA1() override;
	bool ESTOPP_OK_SA2() override;
	bool ESTOPP_QUIT() override;
	bool TST_RESET_KURZ() override;

	bool estopp_flag;

	//void entryStartNode() override;
	//void setFlagEStopp(bool);
	//bool ESTOPP_FALSE_SA1() override;
	//bool TST_RESET_KURZ() override;
	//void initSubState() override;
	//bool estopp_flag;
};



#endif /* SRC_FSM_ESTOPP_ESTOPP_H_ */
