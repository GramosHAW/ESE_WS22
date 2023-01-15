/*
 * DatenEmpfangen.h
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_DATENEMPFANGEN_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_DATENEMPFANGEN_H_

#include "../../../BaseState.h"

class DatenEmpfangen: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool HM_DATA(int data) override;
	bool HM_STOP() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_HOHENMESSER_DATENEMPFANGEN_H_ */
