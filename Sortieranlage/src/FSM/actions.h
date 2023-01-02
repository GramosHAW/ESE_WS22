/*
 * actions.h
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#ifndef SRC_FSM_ACTIONS_H_
#define SRC_FSM_ACTIONS_H_

class Actions {
public:
	virtual ~Actions();
	void addInfo();
	void addQueue();
	void calculateHigh();
	void checkFehler();
	void checkFortschritt();
	void checkSA2();
	void checkSort();
	void createQueue();
	void createWSW();
	void deleteFirstWS();
	void fWsEinstellen();
	void getDataReady();
	void initTimer();
	void initNextTimer();
	void killAll();
	void restoreBandStatus();
	void saveEingabe();
	void saveBandState();
	void sendDataToBroker();
	void sendDataToSA2();
	void setCounter();
	void setFlag();
	void sort();
	void sortAuf();
	void sortZu();
	void uebergangEinstellen();
	void stopTimer();
	void trashData();
	void typeDataRead();
	void wsEinstellen();
	void ZLAeinstellen();
	void ZLDeinstellen();
	void ZNAeinstellen();
	void ZNDeinstellen();



};



#endif /* SRC_FSM_ACTIONS_H_ */
