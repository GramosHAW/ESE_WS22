/*
 * Aktorik.cpp
 *
 *  Created on: 14.04.2022
 *      Author: Noel
 */

#include "Aktorik.h"
#include "../Events.h"
Aktorik* Aktorik::m_pInstance { nullptr };
std::mutex Aktorik::mutex_;
Aktorik *Aktorik::GetInstance() {
	std::lock_guard<std::mutex> lock(mutex_);
	if (m_pInstance == nullptr) {
		m_pInstance = new Aktorik();
	}
	return m_pInstance;
}
Aktorik::Aktorik() {
	this->akt_thread = nullptr;
	this->run_thread = true;
	this->chIdAktorik = ChannelCreate(0);
	if (chIdAktorik == -1) {
		fprintf(stderr, "Dispatcher: Error creating Dispacher Channel %d\n",
		errno);
		exit(1);
	}
	//out32((uintptr_t) (gpio_bank_1 + GPIO_OE), GPIO_IRQSTATUS_CLR_0); //setzt eventuell alle pins auf null
}

Aktorik::~Aktorik() {
	if (-1 == ConnectDetach(chIdAktorik)) {
		fprintf(stderr, "errno = %s", strerror(errno));
		exit(-1);
	}
}

int Aktorik::getchid() {
	return chIdAktorik;
}

void Aktorik::start_aktorik_PulsResiver_THREAD(void) {
	akt_thread = new std::thread(&Aktorik::handelHALpuls, this);
}

void Aktorik::handelHALpuls() {
	_pulse msg;

	while (run_thread) {
		int rcvid = MsgReceivePulse(chIdAktorik, &msg, sizeof(_pulse),
		NULL);
		//std::cout << sizeof(msg);

		if (rcvid != -1) {
			switch (msg.code) {
			//Band
			case PSMG_SW_BAND_START:
				motorRechtslaufAn();
				break;
			case PSMG_SW_BAND_STOP:
				motorRechtslaufAus();
				break;
			case PSMG_SW_BAND_SLOW_AN:
				motorLangsamAn();
				break;
			case PSMG_SW_BAND_SLOW_AUS:
				motorLangsamAus();
				break;
				//Weiche oder Auswerfer
			case PSMG_SW_SORT_DURCH:
				weicheAuf();
				break;
			case PSMG_SE_SORT_AUSSORTIERT:
				sleep(1); //TODO thred fure Weiche(Pooling ist schese)
				weicheZu();
				break;
				//Ampel
			case PSMG_SW_AMPEL_GRUEN_AN:
				ampelGruenAn();
				break;
			case PSMG_SW_AMPEL_GRUEN_BLINK:
				blink_thread = new std::thread(&Aktorik::ampelThread,this, msg.value.sival_int, GRUEN);
				break;
			case PSMG_SW_AMPEL_GRUEN_AUS:
				this->run = false;
				//delete blink_thread;
				ampelGruenAus();
				break;
			case PSMG_SW_AMPEL_GELB_AN:
				ampelGelbAn();
				break;
			case PSMG_SW_AMPEL_GELB_BLINK:
				blink_thread = new std::thread(&Aktorik::ampelThread,this, msg.value.sival_int, GELB);
				break;
			case PSMG_SW_AMPEL_GELB_AUS:
				this->run = false;
				ampelGelbAus();
				break;
			case PSMG_SW_AMPEL_ROT_AN:
				ampelRotAn();
				break;
			case PSMG_SW_AMPEL_ROT_BLINK:
				blink_thread = new std::thread(&Aktorik::ampelThread,this, msg.value.sival_int, ROT);
				break;
			case PSMG_SW_AMPEL_ROT_AUS:
				this->run = false;
				ampelRotAus();
				break;
			}
		}
	}
}

int Aktorik::getAktorikId() {
	return chIdAktorik;
}

void Aktorik::ampelRotAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), ROTE_LAMPE);
}

void Aktorik::ampelRotAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), ROTE_LAMPE);
}

void Aktorik::ampelGelbAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), GELBE_LAMPE);
}

void Aktorik::ampelGelbAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), GELBE_LAMPE);
}

void Aktorik::ampelGruenAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), GRUENE_LAMPE);
}

void Aktorik::ampelGruenAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), GRUENE_LAMPE);
}

void Aktorik::motorRechtslaufAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), MOTOR_RECHTSLAUF);
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), MOTOR_LINKSLAUF);
}

void Aktorik::motorRechtslaufAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), MOTOR_RECHTSLAUF);
}

void Aktorik::motorLinkslaufAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), MOTOR_LINKSLAUF);
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), MOTOR_RECHTSLAUF);
}

void Aktorik::motorLinkslaufAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), MOTOR_LINKSLAUF);
}

void Aktorik::motorLangsamAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), MOTOR_LANGSAM);
}

void Aktorik::motorLangsamAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), MOTOR_LANGSAM);
}

void Aktorik::motorStopAn() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), MOTOR_STOP);
}

void Aktorik::motorStopAus() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), MOTOR_STOP);
}

//für stoßer noch herausfinden
void Aktorik::weicheAuf() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_SETDATAOUT), WEICHE);
}

void Aktorik::weicheZu() {
	out32((uintptr_t) (gpio_bank_1 + GPIO_CLEARDATAOUT), WEICHE);
}

void Aktorik::ampelGruenBlinken() {
	ampelGruenAn();
	usleep(1000 * 1000);
	ampelGruenAus();
	usleep(1000 * 1000);
}

void Aktorik::ampelRotBlinkenSchnell() {
	ampelRotAn();
	usleep(1000 * 500);
	ampelRotAus();
	usleep(1000 * 500);
}

void Aktorik::ampelRotBlinkenLangsam() {
	ampelRotAn();
	usleep(1000 * 1000);
	ampelRotAus();
	usleep(1000 * 1000);
}
// delay -> how many blinks pro sekoed
void Aktorik::ampelThread(int delay, int ampel) {
	ampelRotAus();
	ampelGruenAus();
	ampelGelbAus();
	run = true;
	while (run) {
		switch (ampel) {
		case ROT:
			ampelRotAn();
			usleep(1000000 / delay);
			ampelRotAus();
			usleep(1000000 / delay);
			break;
		case GELB:
			ampelGelbAn();
			usleep(1000000 / delay);
			ampelGelbAus();
			usleep(1000000 / delay);
			break;
		case GRUEN:
			ampelGruenAn();
			usleep(1000000 / delay);
			ampelGruenAus();
			usleep(1000000 / delay);
			break;
		default:;
		}
	}

}

