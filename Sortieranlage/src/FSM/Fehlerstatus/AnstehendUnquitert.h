/*
 * AnstehendUnquitert.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_FEHLERSTATUS_ANSTEHENDUNQUITERT_H_
#define SRC_FSM_FEHLERSTATUS_ANSTEHENDUNQUITERT_H_

#include "../BaseState.h"

class AnstehendUnquitert : public BaseState {

	bool FEHLER_BEHOBEN() override;
	bool FEHLER_BEHOBEN_SA1() override;
	bool FEHLER_BEHOBEN_SA2() override;
	bool TST_RESET_KURZ() override;

	bool FEHLER_QUITI() override;

	void showState() override;
};

#endif /* SRC_FSM_FEHLERSTATUS_ANSTEHENDUNQUITERT_H_ */
