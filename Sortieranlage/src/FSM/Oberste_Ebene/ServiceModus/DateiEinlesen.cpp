/*
 * DateiEinlesen.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "DateiEinlesen.h"
#include <iostream>
#include <stdexcept>


void DateiEinlesen::entry() {
	setReihenfolge('f','l','h', "Reihenfolge.txt");
}

void DateiEinlesen::setReihenfolge(char a, char b, char c, string file) {

	//ContextData::Werkstucktup wstyp = data->flach;

	readDatei(file);

	datei.open(file, ios::trunc | ios::in);

	cout << "data DateiEinlesen: " << data << endl;

	//reihenfolge->push(a);

	switch (a) {
	case 'f':
		datei << a << "\n";
		data->QReihenfolge.push(data->flach);
		break;
	case 'h':
		data->QReihenfolge.push(data->hoch);
		datei << a << "\n";
		break;
	case 'l':
		data->QReihenfolge.push(data->loch);
		datei << a << "\n";
		break;
	case 'm':
		data->QReihenfolge.push(data->metal);
		datei << a << "\n";
		break;
	case 'u':
		data->QReihenfolge.push(data->undefined);
		datei << a << "\n";
	}

	switch (b) {
	case 'f':
		data->QReihenfolge.push(data->flach);
		datei << b << "\n";
		break;
	case 'h':
		data->QReihenfolge.push(data->hoch);
		datei << b << "\n";
		break;
	case 'l':
		data->QReihenfolge.push(data->loch);
		datei << b << "\n";
		break;
	case 'm':
		data->QReihenfolge.push(data->metal);
		datei << b << "\n";
		break;
	case 'u':
		data->QReihenfolge.push(data->undefined);
		datei << b << "\n";
		break;
	}

	switch (c) {
	case 'f':
		data->QReihenfolge.push(data->flach);
		datei << c << "\n";
		break;
	case 'h':
		data->QReihenfolge.push(data->hoch);
		datei << c << "\n";
		break;
	case 'l':
		data->QReihenfolge.push(data->loch);
		datei << c << "\n";
		break;
	case 'm':
		data->QReihenfolge.push(data->metal);
		datei << c << "\n";
		break;
	case 'u':
		data->QReihenfolge.push(data->undefined);
		datei << c << "\n";
		break;
	}

//	data->QReihenfolge.push(data->flach);
//	//q->push(a);
//	datei << a << "\n";
//	//reihenfolge->push(b);
//	datei << b << "\n";
//	//reihenfolge->push(c);
//	datei << c << "\n";

	datei.close();
}


void DateiEinlesen::readDatei(string file) {
	string line;
	ifstream datei (file);
	if (datei.is_open()) {
		while (getline(datei,line)) {
			cout << line << '\n';

		}
		datei.close();
	}
	else cout << "Datei kann nicht geöffnet werden :( " << endl;
}

// TODO


void DateiEinlesen::timeOut() {
	//TODO timeout after 10s, when no data read
}

void DateiEinlesen::showState() {
	cout << "   SubstateSERV: DateiEinlesen " << endl;
}
