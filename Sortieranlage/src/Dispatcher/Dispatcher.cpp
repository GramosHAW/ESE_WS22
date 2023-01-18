#include "Dispatcher.h"
#include "../Events.h"
#include "../HAL/Aktorik.h"
#include "../FSM/ImpulsHandler.h"
#include "../FSM/contextdata.h"
Dispatcher* Dispatcher::m_pInstance { nullptr };
std::mutex Dispatcher::mutex_;
Dispatcher *Dispatcher::GetInstance() {
	std::lock_guard<std::mutex> lock(mutex_);
	if (m_pInstance == nullptr) {
		m_pInstance = new Dispatcher();
	}
	return m_pInstance;
}
Dispatcher::Dispatcher() {
	this->isr_thread = nullptr;
	this->fsmchid = -1;
	this->adcChid = -1;
	this->externChId = -1;
	this->run_thread = true;
	this->dispatcherChannelId = ChannelCreate(0);
	if (dispatcherChannelId == -1) {
		fprintf(stderr, "Dispatcher: Error creating Dispacher Channel %d\n",
		errno);
		exit(1);
	}
	Aktorik* aktorik = Aktorik::GetInstance();
	this->connectionIdHalAktorik = ConnectAttach(0, 0, aktorik->getchid(),
	_NTO_SIDE_CHANNEL, 0);
	if (this->connectionIdHalAktorik == -1) {
		fprintf(stderr,
				"InterruptHandler: Error connecting to Dispacher channel in HAL %d\n",
				errno);
		exit(1);
	}
}

void Dispatcher::set_FSM_chid(int fsmChid) {
	this->fsmchid = fsmChid;
}

void Dispatcher::set_Extern_Ch_Id(int channelId) {
	this->externChId = channelId;
}
void Dispatcher::start_HAL_PulsResiver_THREAD(void) {
	printf("I am about to start Dispatcher\n");
	isr_thread = new thread(&Dispatcher::handelHALpuls, this);
//	isr_thread.detach();
	printf("Ich bin gestartet Dispatcher\n");
}

int Dispatcher::getchid() {
	return dispatcherChannelId;
}

void Dispatcher::set_ADC_chID(int adcChid) {
	this->adcChid = ConnectAttach(0, 0, adcChid, _NTO_SIDE_CHANNEL, 0);
}

void Dispatcher::handelHALpuls() {
	_pulse msg;
	this->fsmchid = ConnectAttach(0, 0, fsmchid,
	_NTO_SIDE_CHANNEL, 0);
	this->externChId = ConnectAttach(0, 0, externChId, _NTO_SIDE_CHANNEL, 0);
	if (externChId == -1) {
		printf("Failure to connect extern Channel");
	}
	while (true) {
/* WSW Übergabe Testkonstrukt + Wenn er das Struct Werkstueck nicht kennt einfach anfang der fkt einfügen, selbe für das Enum.
#ifndef SIM_TWIN_B
		printf("Sending Werkstueck to extern..");
		werkstueck werkstuekTest = {};
		werkstuekTest.flipt = 1;
		werkstuekTest.heightSA1 = 2;
		werkstuekTest.heightSA1mean = 3;
		werkstuekTest.id=4;
		werkstuekTest.tup=flach;
		uintptr_t werkPtrInt = uintptr_t(&werkstuekTest);
		MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT, PSMG_SW_WS_DATA, werkPtrInt);
		sleep(10);
#endif*/

		int rcvid = MsgReceivePulse(dispatcherChannelId, &msg, sizeof(_pulse),
		NULL);
		//std::cout << sizeof(msg);
		if (rcvid != -1) {
			//printf("by Dispatcher resived %d\n", msg.value);
			switch (msg.code) {
			//Lichtschranke///////////////////////////////////////////////////////
			case PSMG_HW_LS_START_FREI:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_START_FREI, 0);
				//TODO
				break;
			case PSMG_HW_LS_START_BLOCK:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_START_BLOCK, 0);
				//SA2
#ifdef SIM_TWIN_B
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_LS_START_BLOCK_SA2, 0);
#endif
				break;
			case PSMG_HW_LS_START_BLOCK_SA2:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_START_BLOCK_SA2, 0);
				break;
			case PSMG_HW_LS_SORT_FREI:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_SORT_FREI, 0);
				break;
			case PSMG_HW_LS_SORT_BLOCK:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_SORT_BLOCK, 0);
				break;
			case PSMG_HW_LS_RUTSCHE_FREI:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_RUTSCHE_BLOCK, 0);
				break;
			case PSMG_HW_LS_RUTSCHE_BLOCK:
				//TODO
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_RUTSCHE_FREI, 0);
				break;
			case PSMG_HW_LS_ENDE_FREI:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_LS_ENDE_FREI, 0);
				break;
			case PSMG_HW_LS_ENDE_BLOCK:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_LS_ENDE_BLOCK, 0);
				break;
				//Taster///////////////////////////////////////////////////////////////
			case PSMG_HW_TST_START_KURZ:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_START_KURZ, 0);
				//printf("Start gedrückt");
				break;
			case PSMG_HW_TST_START_LANG:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_START_LANG, 0);
				break;
			case PSMG_HW_TST_STOP_KURZ:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_STOP_KURZ, 0);
				break;
			case PSMG_HW_TST_STOP_LANG:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_STOP_LANG, 0);
				break;
			case PSMG_HW_TST_RESET_KURZ:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_TST_RESET_KURZ, 0);
				break;
			case PSMG_HW_TST_RESET_LANG:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_LS_ENDE_BLOCK, 0);
				break;
				//Metallsensor//////////////////////////////////////////////////////////////
			case PSMG_HW_MSENS_METALL:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_MSENS_METALL, 0);
				break;
			case PSMG_HW_MSENS_KEIN_METALL:
				//TODO
				break;
				//E-Stopp////////////////////////////////////////////////////////////////////
			case PSMG_HW_E_STOPP_TRUE:
#ifdef SIM_TWIN_B
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_E_STOPP_TRUE_SA2, 0);
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_E_STOPP_TRUE_SA2, 0);
				break;
#else
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_TRUE_SA1, 0);
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_TRUE_SA1, 0);
				break;
#endif
			case PSMG_HW_E_STOPP_FALSE:
#ifdef SIM_TWIN_B
				//Für SA2
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_E_STOPP_FALSE_SA2, 0);
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_HW_E_STOPP_FALSE_SA2, 0);
				break;
#else
				// für SA1
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_FALSE_SA1, 0);
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_FALSE_SA1, 0);
				break;
#endif
			case PSMG_HW_E_STOPP_TRUE_SA1:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_TRUE_SA1, 0);
				break;
			case PSMG_HW_E_STOPP_TRUE_SA2:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_TRUE_SA2, 0);
				break;
			case PSMG_HW_E_STOPP_FALSE_SA1:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_FALSE_SA1, 0);
				break;
			case PSMG_HW_E_STOPP_FALSE_SA2:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_HW_E_STOPP_FALSE_SA2, 0);
				break;
			case PSMG_ESTOPP_OK_SA1:

#ifdef SIM_TWIN_B
				//SA2
				MsgSendPulse(fsmchid,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_ESTOPP_OK_SA1, msg.value.sival_int);
#else
				//SA1
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_ESTOPP_OK_SA1, msg.value.sival_int);
#endif
				break;
			case PSMG_ESTOPP_OK_SA2:
#ifdef SIM_TWIN_B
				//SA2
				MsgSendPulse(externChId,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_ESTOPP_OK_SA2, msg.value.sival_int);
#else				//SA1
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_ESTOPP_OK_SA2, msg.value.sival_int);

#endif
				break;
			case PSMG_SW_ESTOPP_QUIT:
				//SA1

#ifdef SIM_TWIN_B
				MsgSendPulse(externChId,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_SW_ESTOPP_QUIT_SA2, msg.value.sival_int);
#else
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_ESTOPP_QUIT_SA1, msg.value.sival_int);
#endif

				break;
			case PSMG_SW_ESTOPP_QUIT_SA1:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_ESTOPP_QUIT, msg.value.sival_int);
				break;
			case PSMG_SW_ESTOPP_QUIT_SA2:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_ESTOPP_QUIT, msg.value.sival_int);
				break;
				//Hohenmesser//////////////////////////////////////////////////////////////
			case PSMG_SW_HM_START:
				//cout << " HM -starting reding  mesurment" << endl;
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_START, 0);
				break;
			case PSMG_SW_HM_STOP:
				//cout << " HM -stoping reding  mesurment" << endl;
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_STOP, 0);
				//TODO
				break;
			case PSMG_SW_HM_DATA:
				//cout << " HM -Messung wert:" << msg.value.sival_int << endl;
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_DATA, msg.value.sival_int);
				//TODO
				break;
				//////////RUTSCHE///////////////////////////////////////////////////////////////
			case PSMG_SW_SA1_RUTSCHE_VOLL:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SA1_RUTSCHE_VOLL, msg.value.sival_int);
				break;
			case PSMG_SW_SA2_RUTSCHE_VOLL:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SA2_RUTSCHE_VOLL, msg.value.sival_int);
				break;
			case PSMG_SW_RUTSCHE_VOLL_BEIDE:
#ifdef	SIM_TWIN_B
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_SW_RUTSCHE_VOLL_BEIDE_SA2, msg.value.sival_int);
#else
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_RUTSCHE_VOLL_BEIDE_SA1, msg.value.sival_int);
#endif
				break;
			case PSMG_SW_RUTSCHE_VOLL_BEIDE_SA1:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_RUTSCHE_VOLL_BEIDE_SA1, msg.value.sival_int);
				break;
			case PSMG_SW_RUTSCHE_VOLL_BEIDE_SA2:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_RUTSCHE_VOLL_BEIDE_SA2, msg.value.sival_int);
				break;
				///////////LOGIK FÜR ANDERE SEITE///////////////////////////////////////////////
			case PSMG_SW_BETRIEB:
//SA1
#ifdef SIM_TWIN_B
				MsgSendPulse(externChId,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_SW_BETRIEB_SA2, msg.value.sival_int);
#else
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BETRIEB_SA1, msg.value.sival_int);
#endif
				break;
			case PSMG_SW_BETRIEB_SA1:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BETRIEB, msg.value.sival_int);
				break;
			case PSMG_SW_BETRIEB_SA2:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BETRIEB, msg.value.sival_int);
				break;
			case PSMG_SW_RUHE:
#ifdef SIM_TWIN_B
				MsgSendPulse(externChId,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_SW_RUHE_SA2, msg.value.sival_int);
#else
				//SA1
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_RUHE_SA1, msg.value.sival_int);
#endif
				break;
			case PSMG_SW_RUHE_SA1:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_RUHE, msg.value.sival_int);
				break;
			case PSMG_SW_RUHE_SA2:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_RUHE, msg.value.sival_int);
				break;
			case PSMG_SW_SERVICE:

#ifdef SIM_TWIN_B
				MsgSendPulse(externChId,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_SW_SERVICE_SA2, msg.value.sival_int);
#else //SA1
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SERVICE_SA1, msg.value.sival_int);
#endif

				break;
			case PSMG_SW_SERVICE_SA1:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SERVICE, msg.value.sival_int);
				break;
			case PSMG_SW_SERVICE_SA2:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SERVICE, msg.value.sival_int);
				break;
			case PSMG_SW_WS_DATA:
#ifndef SIM_TWIN_B
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_WS_DATA,(uintptr_t) msg.value.sival_ptr);
				break;
#else
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_WS_DATA, (uintptr_t) msg.value.sival_ptr);
				break;
#endif
			case PSMG_SW_BAND_STATUS:
				MsgSendPulse(externChId,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_STATUS_SA1, msg.value.sival_int);
				break;
			case PSMG_SW_BAND_STATUS_SA1:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_STATUS, msg.value.sival_int);
				break;
				/////////////ANDERE LOGIK//////////////////////////////////////////////////////
			case PSMG_SW_SORT_ELMNT_AUSSORT:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SORT_ELMNT_AUSSORT, msg.value.sival_int);
				break;
			case PSMG_SW_SORT_ELMNT_DURCH:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SORT_ELMNT_DURCH, msg.value.sival_int);
				break;
			case PSMG_SW_BAND_FREI:
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_FREI, msg.value.sival_int);
				break;
			case PSMG_SW_BAND_FREI_SA2:
				//SA2
#ifdef SIM_TWIN_B
				MsgSendPulse(externChId,
						SIGEV_PULSE_PRIO_INHERIT,
						PSMG_SW_BAND_FREI_SA2, msg.value.sival_int);

#else
				MsgSendPulse(fsmchid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_FREI_SA2, msg.value.sival_int);

#endif
				break;
				//TO AKTORIK///////////////////////////////////////////////////////////////////////
				//AMPEL////////////////////////////////////////////////////////////////////
			case PSMG_SW_AMPEL_GRUEN_BLINK:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_BLINK, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_GELB_BLINK:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GELB_BLINK, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_ROT_BLINK:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_ROT_BLINK, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_ROT_AUS:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_ROT_AUS, msg.value.sival_int);
				//TODO
				break;
			case PSMG_SW_AMPEL_GRUEN_AUS:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_AUS, msg.value.sival_int);
				break;
			case PSMG_SW_AMPEL_GRUEN_AN:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GRUEN_AN, msg.value.sival_int);
				break;
			case PSMG_SW_AMPEL_GELB_AN:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GELB_AN, msg.value.sival_int);
				break;
			case PSMG_SW_AMPEL_ROT_AN:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_ROT_AN, msg.value.sival_int);
				break;
			case PSMG_SW_AMPEL_GELB_AUS:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_AMPEL_GELB_AUS, msg.value.sival_int);
				break;
				//BAND///////////////////////////////////////////////////////////////////////
			case PSMG_SW_BAND_START:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_START, 0);
				//TODO
				break;
			case PSMG_SW_BAND_STOP:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_STOP, 0);
				break;
			case PSMG_SW_BAND_SLOW_AN:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_SLOW_AN, 0);
				//TODO
				break;
			case PSMG_SW_BAND_SLOW_AUS:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_BAND_SLOW_AUS, 0);
				//TODO
				break;
				//SORT//////////////////////////////////////////////////////////////////////
			case PSMG_SW_SORT_AUSSORTIERT:
				MsgSendPulse(connectionIdHalAktorik, SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SORT_AUSSORTIERT, 0);
				break;
			case PSMG_SW_SORT_AUSSORT:
				MsgSendPulse(connectionIdHalAktorik,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SORT_AUSSORT, 0);
				break;
			case PSMG_SW_SORT_DURCH:
				MsgSendPulse(connectionIdHalAktorik,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_SORT_DURCH, 0);
				break;
			case PSMG_SW_HM_SETWERT:
				MsgSendPulse(adcChid,
				SIGEV_PULSE_PRIO_INHERIT,
				PSMG_SW_HM_SETWERT, msg.value.sival_int);
				break;
#ifndef SIM_TWIN_B
				case PSMG_WS_DATA_TUP:
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_TUP, msg.value.sival_int);
				break;
				case PSMG_WS_DATA_FLIPT:
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_FLIPT, msg.value.sival_int);
				break;
				case PSMG_WS_DATA_HEIGHTSA1:
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_HEIGHTSA1, msg.value.sival_int);
				break;
				case PSMG_WS_DATA_HEIGHTSA1MEAN:
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_HEIGHTSA1MEAN, msg.value.sival_int);
				break;
				case PSMG_WS_DATA_ID:
				MsgSendPulse(externChId, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_ID, msg.value.sival_int);
				break;
#else
			case PSMG_WS_DATA_TUP:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_TUP, msg.value.sival_int);
				break;
			case PSMG_WS_DATA_FLIPT:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_FLIPT, msg.value.sival_int);
				break;
			case PSMG_WS_DATA_HEIGHTSA1:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_HEIGHTSA1, msg.value.sival_int);
				break;
			case PSMG_WS_DATA_HEIGHTSA1MEAN:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT,
						PSMG_WS_DATA_HEIGHTSA1MEAN, msg.value.sival_int);
				break;
			case PSMG_WS_DATA_ID:
				MsgSendPulse(fsmchid, SIGEV_PULSE_PRIO_INHERIT, PSMG_WS_DATA_ID,
						msg.value.sival_int);
				break;
#endif
			default:
				printf("%x", msg.code);
				cout << "Dispacher says: Received uncatched PSMG aka say WAAAT" << endl;
				cout << msg.code << endl;
			}
		}
	}
}

Dispatcher::~Dispatcher() {
	if (-1 == ConnectDetach(dispatcherChannelId)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
	if (-1 == ConnectDetach(connectionIdHalAktorik)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
}
