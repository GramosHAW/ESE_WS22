/*
 * contextdata.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_CONTEXTDATA_H_
#define SRC_FSM_CONTEXTDATA_H_




class ContextData {
private:
	int chID_disp;
	int band_hoehe;

	int mittelwert;

	bool estopp_true = false;
	bool rutsche_voll;

	//ADC_Controller* adc_controller;
public:
	void setFlagEStopp(bool);
	void showFlags();
	bool getEStopp(){return this->estopp_true;}
};


#endif /* SRC_FSM_CONTEXTDATA_H_ */
