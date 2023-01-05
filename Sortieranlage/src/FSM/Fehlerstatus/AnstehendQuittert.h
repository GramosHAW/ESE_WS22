/*
 * AnstehendQuittert.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_FEHLERSTATUS_ANSTEHENDQUITTERT_H_
#define SRC_FSM_FEHLERSTATUS_ANSTEHENDQUITTERT_H_

#include "../BaseState.h"

class AnstehendQuittert : public BaseState {

	bool FEHLER_BEHOBEN() override;
	bool FEHLER_BEHOBEN_SA1() override;
	bool FEHLER_BEHOBEN_SA2() override;
	bool FEHLER_TRUE() override;

	void showState() override;
};

#endif /* SRC_FSM_FEHLERSTATUS_ANSTEHENDQUITTERT_H_ */
