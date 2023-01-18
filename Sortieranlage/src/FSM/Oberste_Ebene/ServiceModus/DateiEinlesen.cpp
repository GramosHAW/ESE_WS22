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

			x += a;
			x += b;
			x += c;
		}

	}
	datei.close();

	a = x.at(0);
	b = x.at(1);
	c = x.at(2);

	cout << a << b << c << "TEST"<< endl ;

	switch (a) {
	case 'f':
		//datei << a << "\n";
		data->QReihenfolge.push(data->flach);
		break;
	case 'h':
		data->QReihenfolge.push(data->hoch);
		//datei << a << "\n";
		break;
	case 'l':
		data->QReihenfolge.push(data->loch);
		//datei << a << "\n";
		break;
	case 'm':
		data->QReihenfolge.push(data->metal);
		//datei << a << "\n";
		break;
	default:
			break;
	}

	switch (b) {
	case 'f':
		data->QReihenfolge.push(data->flach);
		//datei << b << "\n";
		break;
	case 'h':
		data->QReihenfolge.push(data->hoch);
		//datei << b << "\n";
		break;
	case 'l':
		data->QReihenfolge.push(data->loch);
		//datei << b << "\n";
		break;
	case 'm':
		data->QReihenfolge.push(data->metal);
		//datei << b << "\n";
		break;
	default:
			break;
	}

	switch (c) {
	case 'f':
		data->QReihenfolge.push(data->flach);
		//datei << c << "\n";
		break;
	case 'h':
		//data->QReihenfolge.push(data->hoch);
		//datei << c << "\n";
		break;
	case 'l':
		data->QReihenfolge.push(data->loch);
		//datei << c << "\n";
		break;
	case 'm':
		data->QReihenfolge.push(data->metal);
		//datei << c << "\n";
		break;
	default:
		break;
	}
	datei.close();
}


fstream DateiEinlesen::readDatei(string file) {
	string line;
	fstream datei (file);
	if (datei.is_open()) {
		while (getline(datei,line)) {
			cout << line << '\n';

		}
		datei.close();
	}
	else cout << "Datei kann nicht geöffnet werden :( " << endl;
	return datei;
}



// TODO


void DateiEinlesen::timeOut() {
	//TODO timeout after 10s, when no data read
}

void DateiEinlesen::showState() {
	cout << "   SubstateSERV: DateiEinlesen " << endl;
}
