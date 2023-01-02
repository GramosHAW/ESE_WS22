/*
 * DateiEinlesen.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITEN_DATEIEINLESEN_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITEN_DATEIEINLESEN_H_

#include "../../BaseState.h"

class DateiEinlesen : BaseState {
	void showState() override;
	void entry() override;
	void timeOut();
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITEN_DATEIEINLESEN_H_ */
