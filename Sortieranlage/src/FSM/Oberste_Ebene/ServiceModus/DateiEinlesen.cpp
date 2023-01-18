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

	cout << a << b << c << "TEST"<< endl ;

	// im Switch-Case char checken und in Queue packen
	switch (a) {
	case 'f':
		data->folge[0] = data->flach;
		//data->QReihenfolge.push(data->flach);
		break;
	case 'h':
		//data->QReihenfolge.push(data->hoch);
		data->folge[0] = data->hoch;
		break;
	case 'l':
		//data->QReihenfolge.push(data->loch);
		data->folge[0] = data->loch;
		break;
	case 'm':
		//data->QReihenfolge.push(data->metal);
		data->folge[0] = data->metal;
		break;
	default:
			break;
	}

	switch (b) {
	case 'f':
		//data->QReihenfolge.push(data->flach);
		data->folge[1] = data->flach;
		break;
	case 'h':
		//data->QReihenfolge.push(data->hoch);
		data->folge[1] = data->hoch;
		break;
	case 'l':
		//data->QReihenfolge.push(data->loch);
		data->folge[1] = data->loch;
		break;
	case 'm':
		//data->QReihenfolge.push(data->metal);
		data->folge[1] = data->metal;
		break;
	default:
			break;
	}

	switch (c) {
	case 'f':
		//data->QReihenfolge.push(data->flach);
		data->folge[2] = data->flach;
		break;
	case 'h':
		//data->QReihenfolge.push(data->hoch);
		data->folge[2] = data->hoch;
		break;
	case 'l':
		//data->QReihenfolge.push(data->loch);
		data->folge[2] = data->loch;
		break;
	case 'm':
		//data->QReihenfolge.push(data->metal);
		data->folge[2] = data->metal;
		break;
	default:
		break;
	}
	datei.close();

	send_event_payload(PSMG_SW_READDATA_TRUE, 1);

}


bool DateiEinlesen::readDatei() {
	return false;
}



// TODO


void DateiEinlesen::timeOut() {
	//TODO timeout after 10s, when no data read
}

void DateiEinlesen::showState() {
	cout << "   SubstateSERV: DateiEinlesen " << endl;
}
