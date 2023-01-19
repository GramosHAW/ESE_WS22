/*
 * DateiEinlesen.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITEN_DATEIEINLESEN_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITEN_DATEIEINLESEN_H_

#include "../../BaseState.h"
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <fstream>
#include "../../Queue/ThreadsafeQueue.h"
#include "../../contextdata.h"
#include "Standby.h"
#include "../../context.h"

class DateiEinlesen : BaseState {
private:
	//fstream datei;
public:
	void showState() override;
	void entry() override;
	bool TST_STOP_KURZ() override;
	void timeOut();

	void setReihenfolge(string);
private:
	void putINarray(char letter, int plaz);
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_ZEITEN_DATEIEINLESEN_H_ */
