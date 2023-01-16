/*
 * AddNeuesWs.h
 *
 *  Created on: 20 Dec 2022
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_ADDNEUESWS_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_ADDNEUESWS_H_

#include "../../../BaseState.h"

class AddNeuesWs : public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;
private:
	void addtoQueue();
};



#endif /* SRC_FSM_OBERSTE_EBENE_RUNNING_STATES_ADDNEUESWS_H_ */
