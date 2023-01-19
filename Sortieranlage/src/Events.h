#ifndef EVENT_H_
#define EVENT_H_

#include <map>
#include <iostream>
#include <sstream>


    //Lichtschranke
#define		PSMG_HW_LS_START_FREI				0x1
#define		PSMG_HW_LS_HOEHE_FREI				0x2
#define		PSMG_HW_LS_SORT_FREI				0x3
#define		PSMG_HW_LS_RUTSCHE_FREI				0x4
#define		PSMG_HW_LS_ENDE_FREI				0x5
#define		PSMG_HW_LS_START_BLOCK				0x6
#define		PSMG_HW_LS_START_BLOCK_SA2			0x3F
#define		PSMG_HW_LS_HOEHE_BLOCK				0x7
#define		PSMG_HW_LS_SORT_BLOCK				0x8
#define		PSMG_HW_LS_RUTSCHE_BLOCK			0x9
#define		PSMG_HW_LS_ENDE_BLOCK				0xA
	//Taster
#define		PSMG_HW_TST_START_KURZ				0xB
#define		PSMG_HW_TST_STOP_KURZ				0xC
#define		PSMG_HW_TST_RESET_KURZ				0xD
#define		PSMG_HW_TST_START_LANG				0xE
#define		PSMG_HW_TST_STOP_LANG				0xF
#define		PSMG_HW_TST_RESET_LANG				0x10

	//Metalsensor
#define		PSMG_HW_MSENS_METALL				0x11
#define		PSMG_HW_MSENS_KEIN_METALL			0x12
	//E-Stopp
#define		PSMG_HW_E_STOPP_TRUE				0x13
#define		PSMG_HW_E_STOPP_FALSE				0x14
#define 	PSMG_HW_E_STOPP_TRUE_SA1			0x50
#define 	PSMG_HW_E_STOPP_TRUE_SA2			0x51
#define 	PSMG_HW_E_STOPP_FALSE_SA1			0x52
#define 	PSMG_HW_E_STOPP_FALSE_SA2			0x53
#define		PSMG_ESTOPP_OK_SA1					0x55
#define		PSMG_ESTOPP_OK_SA2					0x66
#define		PSMG_SW_ESTOPP_QUIT					0x60
#define		PSMG_SW_ESTOPP_QUIT_SA1				0x61
#define		PSMG_SW_ESTOPP_QUIT_SA2				0x62
	//Unbekannte Ws
#define		PSMG_HW_UNKNOWN_WS					0x15


// ######## SOFTWARE ########


	//Sortieranlagen
#define		PSMG_SW_SA1_BEREIT					0x16
#define		PSMG_SW_SA1_ABBRECHEN				0x17
#define		PSMG_SW_SA2_BEREIT					0x18
#define		PSMG_SW_SA2_ABBRECHEN				0x19

	//Zustände
#define		PSMG_SW_BETRIEB						0x1A
#define		PSMG_SW_BETRIEB_SA1					0x63
#define		PSMG_SW_BETRIEB_SA2					0x64
#define		PSMG_SW_RUHE						0x1B
#define		PSMG_SW_RUHE_SA1					0x65
#define		PSMG_SW_RUHE_SA2					0x67
#define		PSMG_SW_SERVICE						0x1C
#define		PSMG_SW_SERVICE_SA1					0x68
#define		PSMG_SW_SERVICE_SA2					0x69

	//Förderband
#define		PSMG_SW_BAND_START					0x1D
#define		PSMG_SW_BAND_STOP					0x1E
#define		PSMG_SW_BAND_SLOW_AN				0x1F
#define		PSMG_SW_BAND_SLOW_AUS				0x20
#define		PSMG_SW_BAND_FREI					0x21
#define		PSMG_SW_BAND_FREI_SA2				0x54
#define 	PSMG_SW_BAND_STATUS					0x45
#define 	PSMG_SW_BAND_STATUS_SA1				0x56
#define		PSMG_SW_BAND_VOLL					0x22

	//Hoehenmesser
#define		PSMG_SW_HM_START					0x23
#define		PSMG_SW_HM_STOP						0x24
#define     PSMG_SW_HM_DATA                     0x42
#define 	PSMG_SW_HM_CALHOE				    0x43// nicht benuzt momentan
#define 	PSMG_SW_HM_SETWERT 		            0x44

	//Sortierelement
#define     PSMG_SW_SORT_AUSSORTIERT            0x41 // TODO ubenenean
#define		PSMG_SW_SORT_AUSSORT				0x25
#define		PSMG_SW_SORT_DURCH					0x26
#define 	PSMG_SW_SORT_ELMNT_AUSSORT			0x71
#define 	PSMG_SW_SORT_ELMNT_DURCH			0x72

	//Rutschen voll
#define		PSMG_SW_SA1_RUTSCHE_VOLL			0x27
#define		PSMG_SW_SA1_RUTSCHE_FREI			0x28
#define		PSMG_SW_SA2_RUTSCHE_VOLL			0x29
#define		PSMG_SW_SA2_RUTSCHE_FREI			0x2A
#define		PSMG_SW_RUTSCHE_VOLL_BEIDE			0x46
#define		PSMG_SW_RUTSCHE_VOLL_BEIDE_SA1		0x47
#define		PSMG_SW_RUTSCHE_VOLL_BEIDE_SA2		0x48

	//Werkstücke
#define		PSMG_SW_WS_DATA						0x2B
#define		PSMG_SW_WS_SORTED					0x2D
#define		PSMG_SW_WS_ERHALTEN					0x2E
#define		PSMG_SW_WS_FLIPPED					0x2F
//Werkstückdaten
#define 	PSMG_WS_DATA_TUP 					0x49
#define 	PSMG_WS_DATA_FLIPT 					0x4A
#define 	PSMG_WS_DATA_HEIGHTSA1 				0x4B
#define 	PSMG_WS_DATA_HEIGHTSA1MEAN 			0x4C
#define 	PSMG_WS_DATA_ID 					0x4D
	//Ampel
#define		PSMG_SW_AMPEL_GRUEN_AN				0x30
#define		PSMG_SW_AMPEL_GRUEN_BLINK			0x31
#define		PSMG_SW_AMPEL_GRUEN_AUS 			0x32

#define		PSMG_SW_AMPEL_GELB_AN				0x33
#define		PSMG_SW_AMPEL_GELB_BLINK			0x34
#define		PSMG_SW_AMPEL_GELB_AUS				0x35

#define		PSMG_SW_AMPEL_ROT_AN				0x36
#define		PSMG_SW_AMPEL_ROT_BLINK				0x37
#define		PSMG_SW_AMPEL_ROT_AUS				0x38

	//Fehler
#define		PSMG_SW_FEHLER_TRUE					0x39
#define		PSMG_SW_FEHLER_TRUE_SA1				0x4E
#define		PSMG_SW_FEHLER_TRUE_SA2				0x4F
#define		PSMG_SW_FEHLER_WS_FEHLT				0x3A
#define		PSMG_SW_FEHLER_WS_EXTRA				0x3B
#define		PSMG_SW_FEHLER_BEHOBEN 				0x3C
#define		PSMG_SW_FEHLER_QUITTI_TRUE			0x3D
#define		PSMG_SW_FEHLER_QUITTI_FALSE			0x3E
#define		PSMG_SW_FEHLER_ENDE					0x40

 // Interrupt
#define 	PSMG_INTERRUPT						0xAA//stack owerflow!!!!!!

//Data

#define     PSMG_SW_READDATA_TRUE              0x70






#endif /* EVENT_H_ */
