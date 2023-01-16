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
#include "Fehlerstatus/AnstehendUnquitert.h"



void BaseState::initSubState(){
    substateSA = new Ruhezustand;
    substateSA->setData(data);
    substateSA->initSubState();
//  substateBZ = new BIdle;
    substateEST = new estoppStart;
    substateEST->setData(data);
//	substateSERV->initSubState();
    substateKALI = new SortiererEinstellen;
    substateKALI->setData(data);
 // substateZEIT = new BandAnfang;
    substateFEHL = new AnstehendUnquitert;




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
bool BaseState::BAND_FREI_SA2(){
	return false;
}
bool BaseState::LS_START_BLOCK_SA2(){
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

bool BaseState::LS_ENDE_BLOCK_SA2(){
	return false;
}

///////////////////////////Hoenmesser
bool BaseState::HM_START(){
	return false;
}
bool BaseState::HM_STOP(){
	return false;
}
bool BaseState::HM_DATA(int data) {
	return false;
}

//////////////////////////Metalsensor
bool BaseState::MSENS_METALL(){
	return false;
}
bool BaseState::MSENS_METALL_OHNE(){
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

bool BaseState::ESTOPP_QUIT(){
	return false;
}
///////////////////////LOGIC MSG

bool BaseState::BAND_FREI() {
	return false;
}

bool BaseState::BAND_STOP() {
	return false;
}

bool BaseState::SERVICE() {
	return false;
}
bool BaseState::BETRIEB() {
	return false;
}
bool BaseState::RUHE() {
	return false;
}

bool BaseState::BAND_STATUS(){
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
bool BaseState::RUTSCHE_VOLL_SA1(){
	return false;
}


bool BaseState::WSW_OK(){
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


bool BaseState::FEHLER_WSW(){
	return false;
}

bool BaseState::FEHLER_SA1(){
	return false;
}
bool BaseState::FEHLER_SA2(){
	return false;
}
bool BaseState::FEHLER_BEHOBEN_SA1(){
	return false;
}
bool BaseState::FEHLER_BEHOBEN_SA2(){
	return false;
}

//Warnungen
/*
bool BaseState::RUTSCHE_VOLL_SA1(){
	return false;
}
*/
bool BaseState::RUTSCHE_VOLL_SA2(){
	return false;
}
bool BaseState::RUTSCHE_VOLL_BEIDE(){
	return false;
}
bool BaseState::WS_FLIPPED(){
	return false;
}

///////////////////////// READ DATA

bool BaseState::READDATA_TRUE(){
	return false;
}


void BaseState::showState() {
	cout << "You hit rock bottom!!!" << endl;
}

