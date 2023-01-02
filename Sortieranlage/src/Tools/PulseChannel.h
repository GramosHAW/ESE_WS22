

#ifndef PULSECHANNEL_PULSECHANNEL_H_
#define PULSECHANNEL_PULSECHANNEL_H_

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
#include <hw/inout.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/netmgr.h>
#include <sys/siginfo.h>
#include <sys/dispatch.h>
#include <sys/types.h>

class PulseChannel {
private:
	int chid;

public:
	PulseChannel();
	int getChannelId(void);
	struct _pulse Msg_ReceivePulse(void);
	virtual ~PulseChannel();
};

#endif /* PULSECHANNEL_PULSECHANNEL_H_ */
