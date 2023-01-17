/*
 * Ubergabe.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_UBERGABE_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_UBERGABE_H_

#include "../../../BaseState.h"

class Ubergabe: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	void initSubState() override;
	void entryStartNode() override;

	bool LS_ENDE_BLOCK() override;
	bool BAND_FREI_SA2() override;
	bool LS_START_BLOCK_SA2() override;
	bool LS_ENDE_FREI_SA2() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_UBERGABE_H_ */
