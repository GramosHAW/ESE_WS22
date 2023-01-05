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

	bool estopp_true;
	bool anderer_estopp_true;
	bool rutsche_voll;
	bool andere_rutsche_voll;

	//ADC_Controller* adc_controller;

};


#endif /* SRC_FSM_CONTEXTDATA_H_ */
