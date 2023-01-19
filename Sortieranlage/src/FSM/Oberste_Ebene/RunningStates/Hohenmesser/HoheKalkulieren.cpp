/*
 * HoheKalkulieren.cpp
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */
#include "HoheKalkulieren.h"
#include "../../../contextdata.h"
#include "HohenmesserInit.h"

void HoheKalkulieren::entry() {
	calculateHigt();
	exit();
	new (this) HohenmesserInit;
	entry();
}

void HoheKalkulieren::exit() {
	//TODO addInfo()
	data->numberOFmejurments = 0;
}

void HoheKalkulieren::showState() {
	cout << " subsubstateHoenmesser: HoheKalkulieren" << endl;
}

void HoheKalkulieren::calculateHigt() {
	ContextData::Werkstucktup werkstucktup = ContextData::undefined;
	int mittelwert_ausen = 0;
	int mittelwert_mittel = 0;
	for (int i = 1; i < (data->numberOFmejurments / 3) - 5; i++) {
		mittelwert_ausen += data->mejurments[i];
	}
	mittelwert_ausen = mittelwert_ausen / ((data->numberOFmejurments / 3) - 6);
	//printf("mittelwert_ausen = %d \n", mittelwert_ausen);
	for (int i = (data->numberOFmejurments / 2) - 5;
			i < (data->numberOFmejurments / 2) + 5; i++) {
		mittelwert_mittel += data->mejurments[i];
	}
	mittelwert_mittel = mittelwert_mittel / 10;
	//printf("mittelwert_mittel = %d \n", mittelwert_mittel);

	if (mittelwert_ausen > 2345 && mittelwert_ausen < 2400) {
		if (mittelwert_mittel > 3000 && mittelwert_mittel < 3400) {
			printf("mit Loch \n");
			werkstucktup = ContextData::loch;
		} else if (mittelwert_mittel > 2345 && mittelwert_mittel < 2359) {
			printf("Hoh \n");
			werkstucktup = ContextData::hoch;
		} else {
			printf("Undifined \n");
			werkstucktup = ContextData::undefined;
		}
	} else if (mittelwert_ausen > 2576 && mittelwert_ausen < 2592) {
		if (mittelwert_mittel > 2576 && mittelwert_mittel < 2592) {
			printf("Flach \n");
			werkstucktup = ContextData::flach;
		} else {
			printf("Undifined \n");
			werkstucktup = ContextData::undefined;
		}
	}
	if (werkstucktup != ContextData::undefined) {

#ifdef SIM_TWIN_B
		if (werkstucktup !=data->Q1.front()->tup ){
			data->Q1.front()->flipt=1;
			printf("Flipt value: %d\n", data->Q1.front()->flipt);
			send_event(PSMG_SW_WS_FLIPPED);
		}
		data->Q1.front()->tup = werkstucktup;
		data->Q1.front()->heightSA2 = (3640-mittelwert_ausen)*0.3;
#else
		data->Q1.front()->tup = werkstucktup;
		data->Q1.front()->heightSA1 = (3640-mittelwert_ausen)*0.3;
		data->Q1.front()->heightSA1mean= (3640-((mittelwert_ausen+mittelwert_mittel)/2))*0.3;
		data->Q2.push(data->Q1.pop());
#endif

	}

}

