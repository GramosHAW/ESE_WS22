/*
 * SortiererEinstellen.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_SORTIEREREINSTELLEN_H_
#define SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_SORTIEREREINSTELLEN_H_

#include "../../../BaseState.h"

class SortiererEinstellen : public BaseState {

	void sortEinstellen();
	void saveEingabe();

	void showState() override;

	bool TST_START_KURZ() override;
	bool TST_START_LANG() override;
	bool TST_RESET_KURZ() override;
};



#endif /* SRC_FSM_OBERSTE_EBENE_SERVICEMODUS_KALIBRIERUNG_SORTIEREREINSTELLEN_H_ */
