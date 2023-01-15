/*
 * WaitForMetal.h
 *
 *  Created on: 13 Jan 2023
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_WAITFORMETAL_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_WAITFORMETAL_H_

#include "../../../BaseState.h"

class WaitForMetal: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI() override;
	bool MSENS_METALL() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_WAITFORMETAL_H_ */
