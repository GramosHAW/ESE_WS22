/*
 * NormalDurch.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "NormalDurch.h"
#include "ZeitMessen.h"

void NormalDurch::entry() {
	this->showState();


}

void NormalDurch::exit() {

}

bool NormalDurch::ND_Flag() {
//	if (ndFlag) {
//	exit();
//	new (this) ZeitMessen;
//	entry();
//	entryStartNode();
//
//	}
	return true;
}

bool NormalDurch::TST_RESET_KURZ() {
	exit();
	new (this) ZeitMessen;
	entry();
	entryStartNode();

	return true;
}

void NormalDurch::showState() {
	cout << " >> >> >> <SubSubSubState> NormalDurch " << endl;
};




