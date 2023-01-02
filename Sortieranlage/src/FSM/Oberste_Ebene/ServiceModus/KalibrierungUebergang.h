/*
 * KalibrierungUebergang.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNGUEBERGANG_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNGUEBERGANG_H_

#include "../../BaseState.h"

class KalibrierungUebergang : public BaseState {
	void entry() override;
	void exit() override;
	void showState() override;

	//bool LS_START_BLOCK_SA2() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNGUEBERGANG_H_ */
