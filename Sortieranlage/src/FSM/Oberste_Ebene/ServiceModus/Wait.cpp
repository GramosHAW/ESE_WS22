/*
 * Wait.cpp
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */


#include "Wait.h"
#include "KalibrierungUebergang.h"

bool WaitUebergabe::LS_ENDE_BLOCK() {
	exit();
	new (this) KalibrierungUebergang;
	entry();
	return true;
}
/*
void Wait::showState() {
	cout << "   SubstateSERV: Wait " << endl;
}
*/

