/*
 * MetallMessen.cpp
 *
 *  Created on: 28 Dec 2022
 *      Author: andre
 */

#include "MetallMessen.h"
#include "MetallsensorInit.h"

void MetallMessen::entry() {
	showState();
	//TODO AddInfo()
}

void MetallMessen::exit() {

}

void MetallMessen::showState() {
	cout << "  substateMetallsensor: MetallMessen" << endl;
}

bool MetallMessen::MSENS_METALL_OHNE() {
	exit();
	new (this) MetallsensorInit;
	entry();
	return true;
}
