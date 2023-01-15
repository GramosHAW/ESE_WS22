/*
 * Hohenmesser.h
 *
 *  Created on: 20 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHENMESSER_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHENMESSER_H_

#include "../../../BaseState.h"

class Hohenmesser : public BaseState {
public:
	void entryStartNode() override;
	void initSubState() override;

	void entry() override;
	void exit() override;

	void showState() override;

	bool BAND_FREI() override;
	bool HM_START() override;
	bool HM_STOP() override;
	bool HM_DATA(int data) override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_HOHENMESSER_H_ */
