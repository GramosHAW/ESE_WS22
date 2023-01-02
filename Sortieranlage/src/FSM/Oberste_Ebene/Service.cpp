/*
 * Service.cpp
 *
 *  Created on: 09.12.2022
 *      Author: Admin
 */

#include "Service.h"
#include "Ruhezustand.h"

bool Service::TST_STOP_KURZ(){
	exit();
	new(this) Ruhezustand;
	entry();
	return true;
}

void Service::showState(){
	cout << " SubstateSA: Service" << endl;
}

