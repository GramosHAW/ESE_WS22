/*
 * RutscheVoll.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_RUTSCHEVOLL_H_
#define SRC_FSM_WARNUNG_RUTSCHEVOLL_H_

#include "../BaseState.h"

class RutscheVoll: public BaseState {
protected:
	BaseState *substateWARNRUT;
public:
	void entryStartNode() override;
	void initSubState() override;

	bool RUTSCHE_VOLL_SA1() override;
	bool RUTSCHE_VOLL_SA2() override;
	bool RUTSCHE_VOLL_BEIDE() override;
	bool ELMNT_AUSSORT() override;
	bool FEHLER_BEHOBEN() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_RUTSCHEVOLL_H_ */
