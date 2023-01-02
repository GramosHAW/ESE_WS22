/*
 * HohenmesserInit.h
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHENMESSERINIT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHENMESSERINIT_H_

#include "../../../BaseState.h"

class HohenmesserInit : public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI() override;
	bool HM_START() override;
};


#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHENMESSERINIT_H_ */
