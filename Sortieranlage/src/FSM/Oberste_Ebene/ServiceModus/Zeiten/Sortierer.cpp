/*
 * Sortierer.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "Sortierer.h"
#include "BandEnde.h"
#include "Aussortiert.h"

void Sortierer::entry() {

}

void Sortierer::exit() {

}

bool Sortierer::LS_ENDE_BLOCK() {
	exit();
	new (this) BandEnde;
	entry();
	return true;
}

void Sortierer::showState() {
	cout << " >> >> >> Sortierer " << endl;
}


