/*
 * WSFlipped.h
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_WARNUNG_WSFLIPPED_H_
#define SRC_FSM_WARNUNG_WSFLIPPED_H_

#include "../BaseState.h"

class WSFlipped: public BaseState {
protected:
	BaseState *substateWARNFLIP;
public:
	void entryStartNode() override;
	void initSubState() override;

	bool WS_FLIPPED() override;
	bool BAND_FREI() override;
	bool ELMNT_AUSSORT() override;

	void showState() override;
};

#endif /* SRC_FSM_WARNUNG_WSFLIPPED_H_ */
