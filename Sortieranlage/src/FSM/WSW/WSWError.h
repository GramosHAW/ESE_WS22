/*
 * WSWError.h
 *
 *  Created on: 29.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WSW_WSWERROR_H_
#define SRC_FSM_WSW_WSWERROR_H_

#include "../BaseState.h"

class WSWError: public BaseState {
	bool FEHLER_BEHOBEN() override;

	void showState() override;
};

#endif /* SRC_FSM_WSW_WSWERROR_H_ */
