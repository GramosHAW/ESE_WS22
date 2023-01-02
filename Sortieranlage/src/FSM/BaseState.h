/*
 * basestate.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_BASESTATE_H_
#define SRC_FSM_BASESTATE_H_

#include "actions.h"

#include <iostream>
#include <new>
#include <thread>

using namespace std;

class BaseState{
protected:

	Actions *action;
	BaseState *substateSA;
	BaseState *substateBZ;

	unsigned char _PMSG;

	std::thread *thread_basestate_pmsg;

public:
	virtual ~BaseState() {};
	//void setData(ContextData *data){this->data = data;};
	//void setAction(Actions *action){this->action = action;};

	void send_event(int);
	void connect_send();

	virtual void initSubState();
	virtual bool isSubEndState();

	virtual void entryStartNode();
	virtual void entryHistory();
	virtual void entryUp();

	virtual void entry();
	virtual void exit();

	//Tasten
	virtual bool TST_START_KURZ();
	virtual bool TST_START_LANG();
	virtual bool TST_STOP_KURZ();
	virtual bool TST_STOP_LANG();
	virtual bool TST_RESET_KURZ();
	virtual bool TST_RESET_LANG();

	//Lichtschranken
	virtual bool LS_START_BLOCK();
	virtual bool LS_START_FREI();
	virtual bool LS_SORT_BLOCK();
	virtual bool LS_SORT_FREI();
	virtual bool LS_RUTSCHE_BLOCK();
	virtual bool LS_RUTSCHE_FREI();
	virtual bool LS_ENDE_BLOCK();
	virtual bool LS_ENDE_FREI();

	//EStopp
	virtual bool ESTOPP_TRUE_SA1();
	virtual bool ESTOPP_TRUE_SA2();
	virtual bool ESTOPP_FALSE_SA1();
	virtual bool ESTOPP_FALSE_SA2();
	virtual bool ESTOPP_OK();

	//logic Msg
	virtual bool BAND_FREI();
	virtual bool SERVICE();
	virtual bool BETRIEB();
	virtual bool RUHE();

	//Fehler
	virtual bool FEHLER_QUITI();
	virtual bool FEHLER_TRUE();
	virtual bool FEHLER_BEHOBEN();


	//Dev
	virtual void showState();

};



#endif /* SRC_FSM_BASESTATE_H_ */
