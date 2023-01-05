/*
 * WSWaechter.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_WSWAECHTER_H_
#define SRC_FSM_WSW_WSWAECHTER_H_

#include "../BaseState.h"

class WSWaechter : public BaseState {

protected:
	BaseState *substateWSW;

public:
	void entryStartNode() override;
	void entryHistory() override;
	void initSubState() override;

	bool HM_START() override;
	bool LS_SORT_BLOCK() override;
	bool LS_ENDE_BLOCK() override;
	bool LS_ENDE_BLOCK_SA2() override;
	bool LS_RUTSCHE_BLOCK() override;
	bool WSW_OK() override;
	bool FEHLER_WSW() override;

	void showState() override;

};


#endif /* SRC_FSM_WSW_WSWAECHTER_H_ */
