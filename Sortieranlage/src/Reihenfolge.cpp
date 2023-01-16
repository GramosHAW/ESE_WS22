/*
 * Reihenfolge.cpp
 *
 *  Created on: 15.01.2023
 *      Author: Admin
 */

#include "Reihenfolge.h"
#include "FSM/contextdata.h"


Reihenfolge::Reihenfolge() {
	//Reihenfolge* reihenfolge = new Reihenfolge();


}

Reihenfolge::~Reihenfolge() {
	delete reihenfolge;
}

void Reihenfolge::setReihenfolge(string a, string b, string c, string file) {

	ContextData::Werkstucktup wstyp;

	datei.open(file, ios::trunc | ios::in);

	//reihenfolge->push(a);

	//data->Qreihenfolge.push(wstyp = ContextData::flach);
	//q->push(a);
	datei << a << "\n";
	//reihenfolge->push(b);
	datei << b << "\n";
	//reihenfolge->push(c);
	datei << c << "\n";

	datei.close();
}

void Reihenfolge::getReihenfolge() {

}

void Reihenfolge::readDatei(string file) {
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

queue<string>* Reihenfolge::getQueue() {

//	while(!reihenfolge->empty()) {
//		cout << " " << reihenfolge->front();
//		reihenfolge->pop();
//	}
//	cout << endl;


	return reihenfolge;
}
