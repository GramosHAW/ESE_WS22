/*
 * ErrorRutsche.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_ERRORRUTSCHE_H_
#define SRC_FSM_WARNUNG_ERRORRUTSCHE_H_

#include "../BaseState.h"

class ErrorRutsche: public BaseState {
	void entry() override;

	bool FEHLER_BEHOBEN() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_ERRORRUTSCHE_H_ */
