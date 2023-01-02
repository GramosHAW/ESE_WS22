/*
 * Hohenmesser.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */



#include "Hoehenmesser.h"
#include "Sortierer.h"

void Hoehenmesser::entry() {

}

void Hoehenmesser::exit() {

}

bool Hoehenmesser::LS_SORT_BLOCK() {
	exit();
	new (this) Sortierer;
	entry();

	return true;
}

void Hoehenmesser::showState() {
	cout << " >> >> >> Höhenmesser " << endl;
}
