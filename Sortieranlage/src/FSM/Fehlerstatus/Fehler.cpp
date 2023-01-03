/*
 * Fehler.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */
#include "Fehler.h"
#include "../ESTOPP/ESTOPP.h"
#include "../Oberste_Ebene/SA1.h"
#include "AnstehendUnquitert.h"

void Fehler::entryStartNode() {
	new (substateFEHL) AnstehendUnquitert;
	substateFEHL->entry();
}

bool Fehler::FEHLER_TRUE(){
	bool handled = substateFEHL->FEHLER_TRUE();
	return handled;
}

bool Fehler::FEHLER_BEHOBEN() {
	bool handled = substateFEHL->FEHLER_BEHOBEN();
	if (substateFEHL->isSubEndState()) {
		exit();
		new (this) SA1;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}
bool Fehler::FEHLER_QUITI() {
	bool handled = substateFEHL->FEHLER_QUITI();
	if (substateFEHL->isSubEndState()) {
		exit();
		new (this) SA1;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}

bool Fehler::TST_RESET_KURZ(){
	bool handled = substateFEHL->TST_RESET_KURZ();
	if (substateFEHL->isSubEndState()) {
		exit();
		new (this) SA1;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}

bool Fehler::ESTOPP_TRUE_SA1(){
	bool handled = substateFEHL->ESTOPP_TRUE_SA1();
	if (!handled){
		exit();
		new(this) ESTOPP;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}

bool Fehler::ESTOPP_TRUE_SA2(){
	bool handled = substateFEHL->ESTOPP_TRUE_SA2();
	if (!handled){
		exit();
		new(this) ESTOPP;
		entry();
		entryStartNode();
		handled = true;
	}
	return handled;
}



void Fehler::showState(){
	cout << "State: Fehler" << endl;
	substateFEHL->showState();
}
