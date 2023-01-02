/*
 * BandhoeheEinstellen.h
 *
 *  Created on: 22.12.2022
 *      Author: Admin
 */

#include "../../../BaseState.h"

class BandhoeheEinstellen : public BaseState {

	void showState() override;
	void entry() override;
	void exit() override;

	bool TST_START_KURZ() override;
};


