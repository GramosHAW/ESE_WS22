/*
 * contextdata.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_CONTEXTDATA_H_
#define SRC_FSM_CONTEXTDATA_H_

#include "../Queue/ThreadsafeQueue.h"
#include "../MQTT/json.hpp"
#include <iostream>


class ContextData {
private:
	int chID_disp;
	int band_hoehe;

	int mittelwert;

	bool estopp_true = false;
	bool rutsche_voll1 = false;
	bool rutsche_voll2 = false;



	bool uebergabeSendFlag = false;
	//bool rutsche_voll;

	//ADC_Controller* adc_controller;
public:
	//FOR metalsensor
	int mejurments[200];
	int numberOFmejurments = 0;
	int wsID = 1;
	bool readData=false;

	typedef enum Werkstucktup{
			flach,
			hoch,
			loch,
			metal,
			undefined
	} Werkstucktup;

	Werkstucktup folge[3]= {flach, hoch, metal};

	struct werkstueck {
		int id;
		int heightSA1;
		int heightSA1mean;
		int heightSA2;
		Werkstucktup tup;
		int flipt = 0; //auf 1 sezen wenn der WS fipted
	};

	werkstueck* ubergebeneWS;		 //WS was von SA1 kommt
	ThreadsafeQueue<werkstueck*> Q1; //Queue bis zum Hoenmesser
	ThreadsafeQueue<werkstueck*> Q2; //Queue von Hoenmesser bis zum Ausortierer
	ThreadsafeQueue<werkstueck*> Q3; //Queue von Ausortierer bis zum Ende
	ThreadsafeQueue<Werkstucktup> QReihenfolge; //Queue der gelesenen Reihenfolge der Ws

	werkstueck* create_new_werckstuck();
	void setFlagEStopp(bool);
	void setrutsche_voll1(bool);
	void setrutsche_voll2(bool);
	void setuebergabeSendFlag(bool);
	void showFlags();
	bool getEStopp() {
		return this->estopp_true;
	}
	bool getrutsche_voll1() {
			return this->rutsche_voll1;
	}
	bool getrutsche_voll2() {
				return this->rutsche_voll2;
	}
	bool getuebergabeSendFlag(){return this->uebergabeSendFlag;}

	void createJSON(int id, Werkstucktup type, int, int);
};

#endif /* SRC_FSM_CONTEXTDATA_H_ */
