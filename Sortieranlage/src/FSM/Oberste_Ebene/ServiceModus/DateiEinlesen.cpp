/*
 * DateiEinlesen.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "DateiEinlesen.h"
#include <iostream>
#include <stdexcept>
#include <limits>

void DateiEinlesen::entry() {
	showState();
	setReihenfolge("Reihenfolge.txt");
}

void DateiEinlesen::setReihenfolge(string file) {

	//ContextData::Werkstucktup wstyp = data->flach;
	char a;
	char b;
	char c;
	string x;

	ifstream datei("../tmp/Reihenfolge.txt", ios::in);

	if (datei.is_open()) {
		while (datei) {
			string line;
			getline(datei, line);

			a = line[0];
			b = line[1];
			c = line[2];

			//chars wieder in einen String packen (notwendig)
			x += a;
			x += b;
			x += c;
		}

	}
	datei.close();

	//ersten drei chars nehmen
	a = x.at(0);
	b = x.at(1);
	c = x.at(2);

	cout <<"Reihenfolge: "<< a << b << c << endl ;

	// im Switch-Case char checken und in Queue packen
	putINarray(a,0);
	putINarray(b,1);
	putINarray(c,2);

	datei.close();
	send_event_payload(PSMG_SW_READDATA_TRUE, 0);
	data->readData = true;
}

void DateiEinlesen::putINarray(char letter, int plaz){
	switch (letter) {
		case 'f':
			//data->QReihenfolge.push(data->flach);
			data->folge[plaz] = data->flach;
			send_event_payload(PSMG_SW_WS_SEND_ARRAY,data->flach);
			break;
		case 'h':
			//data->QReihenfolge.push(data->hoch);
			data->folge[plaz] = data->hoch;
			send_event_payload(PSMG_SW_WS_SEND_ARRAY,data->hoch);
			break;
		case 'l':
			//data->QReihenfolge.push(data->loch);
			data->folge[plaz] = data->loch;
			send_event_payload(PSMG_SW_WS_SEND_ARRAY,data->loch);
			break;
		case 'm':
			//data->QReihenfolge.push(data->metal);
			data->folge[plaz] = data->metal;
			send_event_payload(PSMG_SW_WS_SEND_ARRAY,data->metal);
			break;
		default:
			break;
		}
}



// TODO
bool DateiEinlesen::TST_STOP_KURZ(){
	if (data->readData) {
		exit();
		new (this) Standby;
		entry();
		return true;
	}
	return false;
}



void DateiEinlesen::timeOut() {
	//TODO timeout after 10s, when no data read
}

void DateiEinlesen::showState() {
	cout << "   SubstateSERV: DateiEinlesen " << endl;
}
