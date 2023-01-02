/*
 * basestate.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "basestate.h"
#include "Oberste_Ebene/Ruhezustand.h"
#include "Oberste_Ebene/BIdle.h"
#include "../Dispatcher/Dispatcher.h"
#include "ESTOPP/estoppStart.h"
#include "Oberste_Ebene/ServiceModus/Standby.h"
#include "Oberste_Ebene/ServiceModus/Kalibrierung/SortiererEinstellen.h"
#include "Oberste_Ebene/ServiceModus/Zeiten/BandAnfang.h"

void BaseState::initSubState(){
    substateSA = new Ruhezustand;
    substateSA->initSubState();
    substateBZ = new BIdle;
    substateEST = new estoppStart;
    substateSERV = new Standby;
    //substateSERV->initSubState();
    substateKALI = new SortiererEinstellen;
    substateZEIT = new BandAnfang;




	thread_basestate_pmsg = nullptr;
	_PMSG = 0;
	_payload = 0;
}

bool BaseState::isSubEndState() {
	return false;
}

void BaseState::entryStartNode() {
	// here should an error be thrown
}

void BaseState::entryHistory() {
	// here should an error be thrown
}

void BaseState::entryUp() {
	// here should an error be thrown
}

void BaseState::entry() {

}

void BaseState::exit() {

}

void BaseState::send_event(int pmsg) {

	_PMSG = pmsg;
	thread_basestate_pmsg = new thread(&BaseState::connect_send, this);
	thread_basestate_pmsg->join();
}

void BaseState::send_event_payload(int pmsg, int payload) {
	_PMSG = pmsg;
	_payload = payload;
	thread_basestate_pmsg = new thread(&BaseState::connect_send, this);
	thread_basestate_pmsg->join();
}

void BaseState::connect_send() {
	Dispatcher* disp = Dispatcher::GetInstance();
	int coid = ConnectAttach(0, 0, disp->getchid(), _NTO_SIDE_CHANNEL, 0);
	MsgSendPulse(coid, -1, _PMSG, _payload);
	ConnectDetach(coid);

}

bool BaseState::TST_START_KURZ() {
	return false;
}

bool BaseState::TST_START_LANG() {
	return false;
}

bool BaseState::TST_STOP_KURZ() {
	return false;
}

bool BaseState::TST_STOP_LANG() {
	return false;
}
bool BaseState::TST_RESET_KURZ() {
	return false;
}
bool BaseState::TST_RESET_LANG() {
	return false;
}

///////////////////////////LICHTSCHRANKEN

bool BaseState::LS_START_BLOCK() {
	return false;
}

bool BaseState::LS_START_FREI() {
	return false;
}
bool BaseState::LS_SORT_BLOCK() {
	return false;
}
bool BaseState::LS_SORT_FREI() {
	return false;
}
bool BaseState::LS_RUTSCHE_BLOCK() {
	return false;
}
bool BaseState::LS_RUTSCHE_FREI() {
	return false;
}
bool BaseState::LS_ENDE_BLOCK() {
	return false;
}
bool BaseState::LS_ENDE_FREI() {
	return false;
}

///////////////////////////Hoenmesser
bool BaseState::HM_START(){
	return false;
}
bool BaseState::HM_STOP(){
	return false;
}

////////////////////////////ESTOPP
bool BaseState::ESTOPP_TRUE_SA1() {
	return false;
}
bool BaseState::ESTOPP_TRUE_SA2() {
	return false;
}
bool BaseState::ESTOPP_FALSE_SA1() {
	return false;
}
bool BaseState::ESTOPP_FALSE_SA2() {
	return false;
}
bool BaseState::ESTOPP_OK() {
	return false;
}
bool BaseState::ESTOPP_OK_SA1() {
	return false;
}


bool BaseState::ESTOPP_OK_SA2() {
	return false;
}
///////////////////////LOGIC MSG

bool BaseState::BAND_FREI() {
	return false;
}

bool BaseState::BAND_STOP() {
	return false;
}

//bool BaseState::BAND_START() {
//	return false;
//}

bool BaseState::SERVICE() {
	return false;
}
bool BaseState::BETRIEB() {
	return false;
}
bool BaseState::RUHE() {
	return false;
}

bool BaseState::ELMNT_AUSSORT(){
	return false;
}

bool BaseState::ELMNT_DURCH(){
	return false;
}

bool BaseState::RUTSCHE_FREI(){
	return false;
}

/////////////////////////FEHLER

bool BaseState::FEHLER_QUITI() {
	return false;
}
bool BaseState::FEHLER_TRUE() {
	return false;
}
bool BaseState::FEHLER_BEHOBEN() {
	return false;
}

///////////////////////// READ DATA

bool BaseState::READDATA_TRUE(){
	return false;
}

void BaseState::showState() {
	cout << "You hit rock bottom!!!" << endl;
}

