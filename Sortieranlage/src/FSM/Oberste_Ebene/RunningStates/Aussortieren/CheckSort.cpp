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
#ifdef SIM_TWIN_B
	ContextData::werkstueck* ws = data->Q1.front();
#else
	ContextData::werkstueck* ws = data->Q2.pop();
#endif
	if (data->getrutsche_voll1()) {
#ifdef SIM_TWIN_B
		if (data->QReihenfolge.front() == ws->tup) {
			send_event(PSMG_SW_SORT_ELMNT_DURCH);
			data->QReihenfolge.pop();
		} else {
			send_event(PSMG_SW_SORT_ELMNT_AUSSORT);
			data->Q1.pop();
			//send_event(PSMG_SW_BAND_FREI);
			//send_event(PSMG_SW_BAND_FREI_SA2);
		}
#else
		send_event(PSMG_SW_SORT_ELMNT_DURCH);
		data->Q3.push(ws);
#endif
	} else if (data->getrutsche_voll2()) {
#ifdef SIM_TWIN_B
		send_event(PSMG_SW_SORT_ELMNT_DURCH);
#else
		if (data->QReihenfolge.front() == ws->tup) {
			send_event(PSMG_SW_SORT_ELMNT_DURCH);
			data->QReihenfolge.pop();
			data->Q3.push(ws);
		} else {
			send_event(PSMG_SW_SORT_ELMNT_AUSSORT);
		}
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
				data->Q1.pop();
				//send_event(PSMG_SW_BAND_FREI);
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
				data->Q3.push(ws);
			} else {
				send_event(PSMG_SW_SORT_ELMNT_AUSSORT);
			}
		} else {
			send_event(PSMG_SW_SORT_ELMNT_DURCH);
			data->Q3.push(ws);
		}
#endif
	}

}
