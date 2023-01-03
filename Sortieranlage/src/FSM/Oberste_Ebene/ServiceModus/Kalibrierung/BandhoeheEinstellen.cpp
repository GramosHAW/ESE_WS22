/*
 * BandhoeheEinstellen.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */


#include "BandhoeheEinstellen.h"
#include "fWsKalibrieren.h"

void BandhoeheEinstellen::entry() {

}

void BandhoeheEinstellen::exit() {

}

bool BandhoeheEinstellen::TST_START_KURZ() {
	exit();
	new (this) fWsKalibrieren;
	entry();
	return true;
}

void BandhoeheEinstellen::showState() {
	cout << "   SubstateKALI: Bandhöhe Einstellen " << endl;
}

