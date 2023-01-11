
#ifndef SRC_HAL_INTERRUPTHANDLER_H_
#define SRC_HAL_INTERRUPTHANDLER_H_

//#include "../PulseChannel/PulseChannel.h"
#include "GPIO.h"

#include "../Tools/PulseChannel.h"

#include <iostream>
#include <memory>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctime>
#include <chrono>
#include <queue>
#include <cstdio>

//Machine
#include <sys/neutrino.h>
//#include <hw/inout.h>
#include <stdint.h>
//#include <sys/mman.h>
#include <sys/netmgr.h>
#include <sys/siginfo.h>
#include <sys/dispatch.h>
#include <sys/types.h>


// in der simulation: start 8, stop 9 reset 10 estop 11
//#include "../utilities.h"

#define INTC_BASE_ADRESS 0x48200000
#define INTC_SIR_IRQ     0x00000040
#define GPIOINT0B        97

#define LS_START	    0x00000004 // low when LB blocked
#define LS_HEIGHT   	0x00000008 // pin 3 low when puck is at the height sensor
#define LS_HEIGHT_OK	0x00000010 // pin 4 high when puck-height is ok
#define LS_SWITCH	    0x00000020  // pin 5 low when puck is at the switch
#define METALL_DETECTED	0x00000080  // pin 7 high when Metall detected
#define SWITCH          0x00004000  // pin 14 high when switch opened
#define LS_RUTSCHE			0x00008000  // pin 15 low when LB blocked
#define LS_END 			0x00100000  // pin 20 low when LB blocked
#define START_BUTTON	0x00400000  // pin 22 high when button pressed
#define STOP_BUTTON		0x00800000  // pin 23 low when button pressed
#define RESET_BUTTON	0x04000000  // pin 26 high when button pressed
#define E_STOP_BUTTON	0x08000000  // pin 27 low when button pressed
#define GPIO_SYSCONFIG        0x10
//?
#define 	INTERRUPT_PULSE						66

using namespace std;
class InterruptHandler {
private:
	std::shared_ptr<GPIO> gpio_port;
	bool run_thread;
	//Used for turning off Ruche wehter
	bool ruche_thread;
	int interrupt_id;
	PulseChannel *channel;

	std::thread * isr_thread;
	struct sigevent event;
	uint8_t my_pulse_code;

	int clientChannelId;
	int connectionIdDispacher;

	//Singleton
	static std::mutex mutex_;
	static InterruptHandler* m_pInstance;

	uint32_t get_activeIRQNUMBER(void);
	void pulseChannel_init(void);
	void init_and_start(void);
	void interrupt_init(void);
	void wait_for_event(void);
	void chek_if_ruche_blocked(void);

protected:
	InterruptHandler();
	~InterruptHandler();
public:
	//Singleton
	InterruptHandler(InterruptHandler &other) = delete;
	void operator=(const InterruptHandler &) = delete;
	static InterruptHandler *GetInstance();
	void start_ISR_THREAD(void);
	void terminate_ISR_THREAD(void);
	void join_ISR_THREAD(void);
	int getClientChannelId();
	void dispacherchanel();

};

#endif /* SRC_HAL_INTERRUPTHANDLER_H_ */
