/*
 * SubEnd.h
 *
 *  Created on: 17.12.2022
 *      Author: 2nerd
 */

#ifndef SRC_FSM_SUBEND_H_
#define SRC_FSM_SUBEND_H_

#include "BaseState.h"

class SubEnd : public BaseState {
public:
	void showState() override{cout << "State: Sub End" << endl;}
	bool isSubEndState() override {return true;}
};



#endif /* SRC_FSM_SUBEND_H_ */
