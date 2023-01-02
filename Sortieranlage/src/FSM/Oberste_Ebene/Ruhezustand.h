/*
 * Ruhezustand.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUHEZUSTAND_H_
#define SRC_FSM_OBERSTE_EBENE_RUHEZUSTAND_H_

#include "../basestate.h"

class Ruhezustand : public BaseState {
public:
	void initSubState() override;

	bool TST_START_KURZ() override;
	bool TST_START_LANG() override;

	void entry() override;
	void exit() override;
	void showState() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_RUHEZUSTAND_H_ */
