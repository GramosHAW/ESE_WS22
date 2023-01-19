/*
 * DuMushi.h
 *
 *  Created on: 18.01.2023
 *      Author: 2nerd
 */

#ifndef FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_DUMUSHI_H_
#define FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_DUMUSHI_H_

#include "../../../BaseState.h"

class WaitiongForUbergabe: public BaseState {
	void entry() override;
	void exit() override;

	bool BAND_FREI_SA2() override;
	bool LS_ENDE_FREI_SA2() override;

	void showState() override;

};

#endif /* FSM_OBERSTE_EBENE_RUNNINGSTATES_UBERGABE_DUMUSHI_H_ */
