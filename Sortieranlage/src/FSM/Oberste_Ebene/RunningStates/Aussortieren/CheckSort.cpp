/*
 * CheckSort.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "CheckSort.h"
#include "Durchlassen.h"
#include "DoAussortieren.h"

void CheckSort::entry() {
	showState();
	//TODO checkFlagRutche(), sort()
}

void CheckSort::exit() {

}

void CheckSort::showState() {
	cout << "  subsubstateAussortieren: CheckSort" << endl;
}

bool CheckSort::ELMNT_AUSSORT() {
	exit();
	new (this) DoAussortieren;
	entry();
	return true;
}

bool CheckSort::ELMNT_DURCH() {
	exit();
	new (this) Durchlassen;
	entry();
	return true;
}

void CheckSort::sort(){
	if(data->getrutsche_voll1()){

	}
	else if(data->getrutsche_voll2()){

	}

}
