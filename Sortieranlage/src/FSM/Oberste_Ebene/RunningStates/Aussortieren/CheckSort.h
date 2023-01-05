/*
 * CheckSort.h
 *
 *  Created on: 22 Dec 2022
 *      Author: der Almechtige
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_CHECKSORT_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_CHECKSORT_H_

#include "../../../BaseState.h"

class CheckSort: public BaseState {
public:
	void entry() override;
	void exit() override;

	void showState() override;

	bool ELMNT_AUSSORT() override;
	bool ELMNT_DURCH() override;

};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_AUSSORTIEREN_CHECKSORT_H_ */
