/*
 * actions.cpp
 *
 *  Created on: 08.12.2022
 *      Author: Admin
 */

#include "actions.h"
#include <iostream>
#include "BaseState.h"

Actions::~Actions(){
    std::cout << "  Actions destructor called" << std::endl;
}

void Actions::addQueue(){
	std::cout << " addQueue aufgerufen " << std::endl;
}

void Actions::createQueue() {
	std::cout << " addQueue aufgerufen " << std::endl;
}


