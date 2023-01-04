/*
 * Fehler.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_FEHLERSTATUS_FEHLER_H_
#define SRC_FSM_FEHLERSTATUS_FEHLER_H_

#include "../BaseState.h"

class Fehler : public BaseState {

	void entryStartNode() override;

	bool FEHLER_TRUE() override;
	bool FEHLER_BEHOBEN() override;
	bool FEHLER_BEHOBEN_SA1() override;
	bool FEHLER_BEHOBEN_SA2() override;
	bool FEHLER_QUITI() override;

	bool TST_RESET_KURZ() override;

	bool ESTOPP_TRUE_SA1() override;
	bool ESTOPP_TRUE_SA2() override;

	void showState() override;
};

#endif /* SRC_FSM_FEHLERSTATUS_FEHLER_H_ */
