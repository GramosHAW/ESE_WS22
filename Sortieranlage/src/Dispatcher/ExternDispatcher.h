/*
 * ExternDispatcher.h
 *
 *  Created on: 25 Nov 2022
 *      Author: Sami
 */

#ifndef SRC_DISPATCHER_EXTERNDISPATCHER_H_
#define SRC_DISPATCHER_EXTERNDISPATCHER_H_

#define ATTACH_POINT "foobarService" //TODO: Better name
#define NO_SERVER 0xAA
#define CONNECTION_OK 0xA0
#define STR_MSG (_IO_MAX + 1)
#define DATA_MSG (_IO_MAX + 2)


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

class ExternDispatcher {
public:
	ExternDispatcher();
	virtual ~ExternDispatcher();
	 int startThread();
private:
	void client(std::promise<int>&&);
	int server();
	std::thread *tExtern;
	bool run_thread;
	typedef struct _pulse header_t;

	static void handle_app_msg(header_t hdr, int rcvid);
	static void handle_ONX_IO_msg(header_t hdr, int rcvid);
	static void handle_pulse(header_t hdr, int rcvid);
};
typedef struct _pulse header_t;
/* Second header: used by application - if required */
typedef struct {
	int size; // size of data block
	int count; // some counter used by the application
// further data fields required by application
} app_header_t;
#endif /* SRC_DISPATCHER_EXTERNDISPATCHER_H_ */
