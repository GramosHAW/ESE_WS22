/*
 * contextdata.h
 *
 *  Created on: 19.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_CONTEXTDATA_H_
#define SRC_FSM_CONTEXTDATA_H_

#include "../HAL/ADCreader.h"


class ContextData {

private:
	int chID_disp;
	int band_hoehe;

	int mittelwert;

	bool estopp;
	bool anderer_estopp;

	bool estopp_flag;

	bool rutsche_voll;
	bool andere_rutsche_voll;

	bool auswerfer;
	bool weiche;

	bool ND_flag;
	bool NA_flag;
	bool LD_flag;
	bool LA_flag;

public:
	ContextData();
	virtual ~ContextData();


	void setBandHoehe(int band_hoehe);
	int getBandHoehe();

	void sortEinstellen(char sortiereinheit);
	void uebergangEinstellen();

	void setFlagEStopp();


	bool Rutsche1voll();
	void setRutsche1voll();

	bool Rutsche2voll();
	void setRutsche2voll();

};


#endif /* SRC_FSM_CONTEXTDATA_H_ */
