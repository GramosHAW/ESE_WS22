/*
 * Service.h
 *
 *  Created on: 09.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICE_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICE_H_

#include "../../BaseState.h"

class Service : public BaseState {
	//bool TST_STOP_KURZ() override;

	void showState() override;
	void entry() override;
	void exit() override;

	void initSubState() override;
	void entryStartNode() override;

	bool TST_START_KURZ() override;
	bool TST_STOP_KURZ() override;
	bool TST_RESET_KURZ() override;
	bool TST_RESET_LANG() override;
	bool TST_START_LANG() override;
	bool LS_ENDE_BLOCK() override;
	bool RUHE() override;

	bool HM_START() override;
	bool LS_START_BLOCK() override;
	bool LS_SORT_BLOCK() override;
	bool LS_RUTSCHE_BLOCK() override;

	//bool BAND_START() override;

	// bool LS_START_BLOCK_SA2() override;
public:
	bool readdata_flag;

};




#endif /* SRC_FSM_OBERSTE_EBENE_SERVICE_H_ */
