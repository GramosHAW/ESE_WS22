/*
 * contextdata.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_CONTEXTDATA_H_
#define SRC_FSM_CONTEXTDATA_H_

#include "../Queue/ThreadsafeQueue.h"

class ContextData {
private:
	int chID_disp;
	int band_hoehe;

	int mittelwert;

	bool estopp_true = false;
	bool rutsche_voll;

	//ADC_Controller* adc_controller;
public:
	//FOR metalsensor
	int mejurments[200];
	int numberOFmejurments = 0;
	enum Werkstucktup{
			flach,
			hoch,
			loch,
			metal,
			undefined
	};

	struct werkstueck {
		int id;
		int heightSA1;
		int heightSA2;
		//std::string Typ;
		/*
		werkstueck() {

		}
		*/
	};

	ThreadsafeQueue<werkstueck*> Q1; //Queue bis zum Hoenmesser
	ThreadsafeQueue<werkstueck*> Q2; //Queue von Hoenmesser bis zum Ausortierer
	ThreadsafeQueue<werkstueck*> Q3; //Queue von Ausortierer bis zum Ende

	werkstueck* create_new_werckstuck();
	void setFlagEStopp(bool);
	void showFlags();
	bool getEStopp() {
		return this->estopp_true;
	}
};

#endif /* SRC_FSM_CONTEXTDATA_H_ */
