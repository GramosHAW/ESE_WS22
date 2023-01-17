/*
 * basestate.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_BASESTATE_H_
#define SRC_FSM_BASESTATE_H_

#include "actions.h"
#include "contextdata.h"
#include "../Events.h"

#include <iostream>
#include <new>
#include <thread>

using namespace std;

class BaseState {
protected:

	ContextData *data;
	Actions *action;

	BaseState *substateSA;
	BaseState *substateBZ;
	BaseState *substateEST;


	BaseState *substateSERV;
	BaseState *substateKALI;
	BaseState *substateZEIT;

	BaseState *substateFEHL;

	BaseState *substateNeuesWerckstuck;
	BaseState *subsubstateNeuesWerckstuck;

	BaseState *substateHoenmesser;
	BaseState *subsubstateHoenmesser;

	BaseState *substateAussortieren;
	BaseState *subsubstateAussortieren;

	BaseState *substateRutsche;
	BaseState *subsubstateRutsche;

	BaseState *substateMetallsensor;
	BaseState *subsubstateMetallsensor;

	BaseState *substateUbergabe;
	BaseState *subsubstateUbergabe;

	BaseState *substateEntnahme;
	BaseState *subsubstateEntnahme;



	unsigned char _PMSG;
	unsigned char _payload;

	std::thread *thread_basestate_pmsg;

public:
	virtual ~BaseState() {}
	void setData(ContextData *data){this->data = data;}
	ContextData* getData(){return this->data;};
	//void setAction(Actions *action){this->action = action;};

	void send_event(int);
	void connect_send();
	void send_event_payload(int, int);
	void newWSW();
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
	virtual bool LS_START_BLOCK_SA2();
	virtual bool LS_SORT_BLOCK();
	virtual bool LS_SORT_FREI();
	virtual bool LS_RUTSCHE_BLOCK();
	virtual bool LS_RUTSCHE_FREI();
	virtual bool LS_ENDE_BLOCK();
	virtual bool LS_ENDE_FREI();
	virtual bool LS_ENDE_BLOCK_SA2();
	virtual bool LS_ENDE_FREI_SA2();

	//Hoenmesser
	virtual bool HM_START();
	virtual bool HM_STOP();
	virtual bool HM_DATA(int data);

	//Metalsensor
	virtual bool MSENS_METALL();
	virtual bool MSENS_METALL_OHNE();

	//EStopp
	virtual bool ESTOPP_TRUE_SA1();
	virtual bool ESTOPP_TRUE_SA2();
	virtual bool ESTOPP_FALSE_SA1();
	virtual bool ESTOPP_FALSE_SA2();
	virtual bool ESTOPP_OK();
	virtual bool ESTOPP_OK_SA1();
	virtual bool ESTOPP_OK_SA2();
	virtual bool ESTOPP_QUIT();

	//logic Msg
	virtual bool BAND_FREI();
	virtual bool BAND_FREI_SA2();
	virtual bool BAND_STOP();
	virtual bool SERVICE();
	virtual bool BETRIEB();
	virtual bool RUHE();
	virtual bool BAND_STATUS();
	virtual bool ELMNT_AUSSORT();
	virtual bool ELMNT_DURCH();
	virtual bool RUTSCHE_FREI();

	virtual bool WSW_OK();

	//Fehler
	virtual bool FEHLER_QUITI();
	virtual bool FEHLER_TRUE();
	virtual bool FEHLER_BEHOBEN();
	virtual bool FEHLER_WSW();
	virtual bool FEHLER_SA1();
	virtual bool FEHLER_SA2();
	virtual bool FEHLER_BEHOBEN_SA1();
	virtual bool FEHLER_BEHOBEN_SA2();




	virtual bool READDATA_TRUE();


	//Warnungen
	virtual bool RUTSCHE_VOLL_SA1();
	virtual bool RUTSCHE_VOLL_SA2();
	virtual bool RUTSCHE_VOLL_BEIDE();
	virtual bool WS_FLIPPED();


	//Dev
	virtual void showState();

};

#endif /* SRC_FSM_BASESTATE_H_ */
