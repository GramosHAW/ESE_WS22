/*
 * MetallMessen.h
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_METALLMESSEN_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_METALLMESSEN_H_

#include "../../../BaseState.h"

class MetallMessen: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool MSENS_METALL_OHNE() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_METALLSENSOR_METALLMESSEN_H_ */
