/*
 * BIdle.h
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_OBERSTE_EBENE_BIDLE_H_
#define SRC_FSM_OBERSTE_EBENE_BIDLE_H_


#include "../BaseState.h"

class BIdle : public BaseState {
public:
	void entry() override;
	void exit() override;

	bool LS_START_BLOCK() override;
	bool TST_STOP_KURZ() override;
	//bool LS_START_FREI() override;
	bool RUHE() override;
	bool BAND_STATUS() override;

	void showState() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_BIDLE_H_ */
