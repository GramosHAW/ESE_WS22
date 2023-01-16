/*
 * HoheKalkulieren.cpp
 *
 *  Created on: 20 Dec 2022
 *      Author: The Hive
 */
#include "HoheKalkulieren.h"
#include "../../../contextdata.h"


void HoheKalkulieren::entry(){
	showState();
	//TODO calchight()
}

void HoheKalkulieren::exit() {
	//TODO addInfo()
}

void HoheKalkulieren::showState(){
	cout << " subsubstateHoenmesser: HoheKalkulieren" << endl;
}

void HoheKalkulieren::calculateHigt() {
	ContextData::Werkstucktup werkstucktup;
	int mittelwert_ausen = 0;
	int mittelwert_mittel = 0;
	for (int i = 0; i < 40; i++) {
		mittelwert_ausen += data->mejurments[i];
	}
	mittelwert_ausen = mittelwert_ausen / 40;
	printf("mittelwert_ausen = %d \n", mittelwert_ausen);
	for (int i = 60; i < 120; i++) {
		mittelwert_mittel += data->mejurments[i];
	}
	mittelwert_mittel = mittelwert_mittel / 60;
	printf("mittelwert_mittel = %d \n", mittelwert_mittel);

	if (mittelwert_ausen > 2100 && mittelwert_ausen < 2400) {
		if (mittelwert_mittel > 2900 && mittelwert_mittel < 3250) {
			printf("mit Loch \n");
			werkstucktup = ContextData::loch;
		} else if (mittelwert_mittel > 2100 && mittelwert_mittel < 2300) {
			printf("Hoh \n");
			werkstucktup = ContextData::hoch;
		} else {
			printf("Undifined \n");
			werkstucktup = ContextData::undefined;
		}
	} else if (mittelwert_ausen > 2400 && mittelwert_ausen < 2599) {
		if (mittelwert_mittel > 2400 && mittelwert_mittel < 2599) {
			printf("Flach \n");
			werkstucktup = ContextData::flach;
		} else {
			printf("Undifined \n");
			werkstucktup = ContextData::undefined;
		}
	}

}

