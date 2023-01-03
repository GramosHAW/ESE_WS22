/*
 * Respond.cpp
 *
 *  Created on: 03.01.2023
 *      Author: 2nerd
 */

#include "Respond.h"
#include "Running.h"

bool Respond::LS_START_BLOCK(){
	exit();
	new(this) Running;
	entry();
	return true;
}
