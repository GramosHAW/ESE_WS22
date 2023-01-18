/*
 * Entnahme.h
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_ENTNAHME_ENTNAHME_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_ENTNAHME_ENTNAHME_H_

#include "../../../BaseState.h"

class Entnahme: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;
	void initSubState() override;

	void entryStartNode() override;

	bool BAND_FREI() override;
	bool LS_ENDE_BLOCK() override;
	bool LS_ENDE_FREI() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_ENTNAHME_ENTNAHME_H_ */
