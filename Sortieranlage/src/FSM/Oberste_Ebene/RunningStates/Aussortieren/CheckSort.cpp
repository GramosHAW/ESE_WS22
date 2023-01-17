/*
 * CheckSort.cpp
 *
 *  Created on: 22 Dec 2022
 *      Author: Borat
 */
#include "CheckSort.h"
#include "Durchlassen.h"
#include "DoAussortieren.h"
#include "../../../contextdata.h"

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

void CheckSort::sort() {
	ContextData::werkstueck* ws = data->Q2.pop();
	if (data->getrutsche_voll1()) {
#ifdef SIM_TWIN_B
		//A2 ales ausort
#else
		send_event(PSMG_SW_SORT_ELMNT_DURCH);
#endif
	} else if (data->getrutsche_voll2()) {
#ifdef SIM_TWIN_B

#else
		//A1 alles ausort
#endif
	} else {
#ifdef SIM_TWIN_B
		if(ws->tup != ContextData::flach) {
			if(data->QReihenfolge.front() == ws->tup) {
				send_event(PSMG_SW_SORT_ELMNT_DURCH);
				data->QReihenfolge.pop();
			}
			else {
				send_event(PSMG_SW_SORT_ELMNT_AUSSORT);
			}
		}
		else {
			send_event(PSMG_SW_SORT_ELMNT_DURCH);
		}

#else
		if (ws->tup == ContextData::flach) {
			if (data->QReihenfolge.front() == ContextData::flach) {
				send_event(PSMG_SW_SORT_ELMNT_DURCH);
				data->QReihenfolge.pop();
			} else {
				send_event(PSMG_SW_SORT_ELMNT_AUSSORT);
			}
		} else {
			send_event(PSMG_SW_SORT_ELMNT_DURCH);
		}
#endif
	}

}
