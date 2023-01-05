/*
 * MetallsensorInit.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_METALLSENSORINIT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_METALLSENSORINIT_H_

#include "../../../BaseState.h"

class MetallsensorInit: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI() override;
	bool MSENS_METALL() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_METALLSENSORINIT_H_ */
