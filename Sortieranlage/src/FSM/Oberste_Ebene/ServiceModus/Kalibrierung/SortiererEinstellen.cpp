/*
 * SortiererEinstellen.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */


#include "SortiererEinstellen.h"
#include "fWsKalibrieren.h"
#include "BandhoeheEinstellen.h"

void SortiererEinstellen::entry() {
	this->showState();
}

void SortiererEinstellen::exit() {

}

void SortiererEinstellen::sortEinstellen() {
}

bool SortiererEinstellen::TST_START_KURZ() {
	exit();
	saveEingabe();
	new (this) BandhoeheEinstellen;
	entry();
	return true;
}

bool SortiererEinstellen::TST_START_LANG() {
	exit();
	saveEingabe();
	new (this) BandhoeheEinstellen;
	entry();
	return true;
}

bool SortiererEinstellen::TST_RESET_KURZ() {
	exit();
	new (this) BandhoeheEinstellen;
	entry();
	return true;
}

void SortiererEinstellen::saveEingabe() {
	//TODO
}

void SortiererEinstellen::showState() {
	cout << " >> >> <SubSubState> SortiererEinstellen " << endl;
}

