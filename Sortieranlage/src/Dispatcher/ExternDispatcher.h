/*
 * ExternDispatcher.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Sami
 */

#ifndef SRC_DISPATCHER_EXTERNDISPATCHER_H_
#define SRC_DISPATCHER_EXTERNDISPATCHER_H_

#ifdef SIM_TWIN_B
#define ATTACH_POINT_CLIENT "Server"
#define ATTACH_POINT_SERVER "Client"
#else
#define ATTACH_POINT_SERVER "Server"
#define ATTACH_POINT_CLIENT "Client"
#endif

#define STR_MSG (_IO_MAX + 1)
#define DATA_MSG (_IO_MAX + 2)
#define WERKSTUECK0 0x49
#define WERKSTUECK1 0x4A
#define WERKSTUECK2 0x4B
#define WERKSTUECK3 0x4C
#define WERKSTUECK4 0x4D

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/iofunc.h>
#include <thread>
#include <future>
#include "Dispatcher.h"
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include "../Events.h"
#include <cstdint>

	enum Werkstucktup{
			flach,
			hoch,
			loch,
			metal,
			undefined
	};

	struct werkstueck {
		int id;
		int heightSA1;
		int heightSA1mean;
		int heightSA2;
		Werkstucktup tup;
		int flipt = 0; //auf 1 sezen wenn der WS fipted
	};
class ExternDispatcher {

public:
	ExternDispatcher();
	virtual ~ExternDispatcher();
	void startThread();
	int getchid();
private:
	void client();
	int server();
	int sendMsg(const char* payload, int server_coid, char *returnMsg);
	std::thread *tExtern;
	bool run_thread;
	typedef struct _pulse header_t;
	int externChid;

	int server_coid;
	int dispatcherServer;
	werkstueck werk;
	static void handle_app_msg(header_t hdr, int rcvid);
	static void handle_QNX_IO_msg(header_t hdr, int rcvid);
	void handle_pulse(header_t hdr, int rcvid);
	void sendWerkstueck(werkstueck* );
};
typedef struct _pulse header_t;
/* Second header: used by application - if required */
typedef struct {
	int size; // size of data block
	int count; // some counter used by the application
// further data fields required by application
} app_header_t;
#endif /* SRC_DISPATCHER_EXTERNDISPATCHER_H_ */
