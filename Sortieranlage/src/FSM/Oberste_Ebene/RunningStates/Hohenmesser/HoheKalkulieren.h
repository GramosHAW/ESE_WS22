/*
 * HoheKalkulieren.h
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHEKALKULIEREN_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHEKALKULIEREN_H_

#include "../../../BaseState.h"

class HoheKalkulieren: public BaseState {
public:
	void showState() override;

	void entry() override;
	void exit() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHEKALKULIEREN_H_ */
