/*
 * ZeitMessen.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITMESSEN_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITMESSEN_H_



#include "../../../BaseState.h"

class ZeitMessen : public BaseState {

	void initSubState() override;
	void entryStartNode() override;
	void showState() override;
	void entry() override;
	void exit() override;

	bool TST_START_KURZ() override;
	bool TST_START_LANG() override;
	bool TST_RESET_KURZ() override;
	bool HM_START() override;
	bool LS_START_BLOCK() override;
	bool LS_SORT_BLOCK() override;
	bool LS_ENDE_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;



};

#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITMESSEN_H_ */
