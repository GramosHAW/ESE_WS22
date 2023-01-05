/*
 * EntnahmeSendData.h
 *
 *  Created on: 4 Jan 2023
 *      Author: andre
 */

#ifndef SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_ENTNAHME_ENTNAHMESENDDATA_H_
#define SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_ENTNAHME_ENTNAHMESENDDATA_H_

#include "../../../BaseState.h"

class EntnahmeSendData: public BaseState {
	void entry() override;
	void exit() override;

	void showState() override;

	bool LS_ENDE_FREI() override;
};

#endif /* SRC_FSM_OBERSTE_EBENE_RUNNINGSTATES_ENTNAHME_ENTNAHMESENDDATA_H_ */
