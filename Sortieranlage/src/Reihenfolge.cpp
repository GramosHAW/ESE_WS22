/*
 * Reihenfolge.cpp
 *
 *  Created on: 15.01.2023
 *      Author: Admin
 */

#include "Reihenfolge.h"


Reihenfolge::Reihenfolge() {
	//Reihenfolge* reihenfolge = new Reihenfolge();
	//ThreadsafeQueue q = new ThreadsafeQueue();


}

Reihenfolge::~Reihenfolge() {
	delete reihenfolge;
}

void Reihenfolge::setReihenfolge(string a, string b, string c, string file) {


	datei.open(file, ios::trunc | ios::in);

	//reihenfolge->push(a);
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
