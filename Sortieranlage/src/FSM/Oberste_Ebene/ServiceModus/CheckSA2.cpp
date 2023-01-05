/*
 * CheckSA2.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "CheckSA2.h"
#include "Standby.h"

void CheckSA2::entry(){

}

bool CheckSA2::TST_STOP_KURZ() {
	exit();
	new (this) Standby;
	entry();
	return true;
}

void CheckSA2::showState() {
	cout << "   SubstateSERV: CheckSA2 " << endl;
}
