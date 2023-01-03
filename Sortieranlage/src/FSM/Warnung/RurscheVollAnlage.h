/*
 * RurscheVollAnlage.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_RURSCHEVOLLANLAGE_H_
#define SRC_FSM_WARNUNG_RURSCHEVOLLANLAGE_H_

#include "../BaseState.h"

class RurscheVollAnlage : public BaseState {
	bool RUTSCHE_VOLL_SA2() override;
	bool RUTSCHE_VOLL_SA1() override;
	bool RUTSCHE_VOLL_BEIDE() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_RURSCHEVOLLANLAGE_H_ */
