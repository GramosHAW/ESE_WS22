/*
 * GegangenUnquittiert.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_FEHLERSTATUS_GEGANGENUNQUITTIERT_H_
#define SRC_FSM_FEHLERSTATUS_GEGANGENUNQUITTIERT_H_

#include "../BaseState.h"

class GegangenUnquittiert : public BaseState {
	bool FEHLER_TRUE() override;
	bool FEHLER_QUITI() override;
	bool TST_RESET_KURZ() override;

	void showState() override;
};

#endif /* SRC_FSM_FEHLERSTATUS_GEGANGENUNQUITTIERT_H_ */
