/*
 * ConnectionLostEStopp.h
 *
 *  Created on: 20.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_ESTOPP_CONNECTIONLOSTESTOPP_H_
#define SRC_FSM_ESTOPP_CONNECTIONLOSTESTOPP_H_

#include "../BaseState.h"

class ConnectionLostEStopp : public BaseState {
	void checkEStopp();
	bool FEHLER_BEHOBEN() override;
};



#endif /* SRC_FSM_ESTOPP_CONNECTIONLOSTESTOPP_H_ */
