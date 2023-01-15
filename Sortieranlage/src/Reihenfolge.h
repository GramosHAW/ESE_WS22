/*
 * Reihenfolge.h
 *
 *  Created on: 15.01.2023
 *      Author: Admin
 */

#ifndef REIHENFOLGE_H_
#define REIHENFOLGE_H_


#include <stdlib.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <fstream>


using namespace std;

class Reihenfolge {

private:
	queue<std::string>* reihenfolge;
	ofstream datei;
public:
	Reihenfolge();
	virtual ~Reihenfolge();
	void readDatei(string);
	void setReihenfolge(string, string, string, string);
	void getReihenfolge();
	queue<string>* getQueue();
};

#endif /* REIHENFOLGE_H_ */
