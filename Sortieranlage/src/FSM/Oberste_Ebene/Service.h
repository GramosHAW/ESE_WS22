/*
 * Service.h
 *
 *  Created on: 09.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICE_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICE_H_

#include "../BaseState.h"

class Service : public BaseState {
	bool TST_STOP_KURZ() override;

	void showState() override;
};




#endif /* SRC_FSM_OBERSTE_EBENE_SERVICE_H_ */
