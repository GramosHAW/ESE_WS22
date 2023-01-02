/*
 * Hohenmesser.h
 *
 *  Created on: 22 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_HOHENMESSER_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_HOHENMESSER_H_

#include "../../../BaseState.h"

class Hoehenmesser : public BaseState {
	void entry() override;
	void exit() override;
	void showState() override;
	//bool TST_RESET_KURZ() override;
	bool LS_SORT_BLOCK() override;

};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_HOHENMESSER_H_ */
