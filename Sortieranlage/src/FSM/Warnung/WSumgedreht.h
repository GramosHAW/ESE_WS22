/*
 * WSumgedreht.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_WSUMGEDREHT_H_
#define SRC_FSM_WARNUNG_WSUMGEDREHT_H_

#include "../BaseState.h"

class WSumgedreht: public BaseState {
	bool WSW_OK() override;
	bool ELMNT_AUSSORT() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_WSUMGEDREHT_H_ */