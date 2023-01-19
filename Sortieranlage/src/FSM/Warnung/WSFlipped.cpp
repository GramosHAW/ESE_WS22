/*
 * WSFlipped.cpp
 *
 *  Created on: 27.12.2022
 *      Author: 2nerd
 */

#include "WSFlipped.h"
#include "IdleFlipped.h"

void WSFlipped::entryStartNode(){
	new (substateWARNFLIP) IdleFlipped;
	substateWARNFLIP->entry();
}
void WSFlipped::initSubState(){
	substateWARNFLIP = new IdleFlipped;
}

bool WSFlipped::ELMNT_AUSSORT(){
	bool handled = substateWARNFLIP->ELMNT_AUSSORT();
	return handled;
}

bool WSFlipped::WS_FLIPPED(){
	bool handled = substateWARNFLIP->WS_FLIPPED();
	return handled;
}
bool WSFlipped::BAND_FREI(){
	bool handled = substateWARNFLIP->BAND_FREI();
	return handled;
}

void WSFlipped::showState() {
	cout << "State: WSFlipped" << endl;
	substateWARNFLIP->showState();
}
