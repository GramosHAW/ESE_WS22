/*
 * ExternDispatcher.cpp
 *
 *  Created on: 25 Nov 2022
 *      Author: Sami Askar
 */

#include "ExternDispatcher.h"

ExternDispatcher::ExternDispatcher() {
	this->tExtern = nullptr;
	this->run_thread = true;
	this->externChid = ChannelCreate(0);
	this->server_coid=0;
	this->dispatcherServer = 0;
	this->werk={};

}

ExternDispatcher::~ExternDispatcher() {
}

void ExternDispatcher::client() {
	do {
		this->server_coid = name_open(ATTACH_POINT_CLIENT, NAME_FLAG_ATTACH_GLOBAL);

	} while (server_coid == -1);
	printf("Connected to server! \n");

	return;
}

int ExternDispatcher::sendMsg(const char* payload, int server_coid,
		char *returnMsg) {
	iov_t iov[3]; // multi part msg
	header_t header;
	app_header_t app_header;
	int payload_size = strlen(payload) + 1; // +1 due to string end (\0)
	header.type = STR_MSG; // define msg type
	header.subtype = 0x00;
	app_header.size = payload_size; // fill application header
	app_header.count = 0;
	SETIOV(iov + 0, &header, sizeof(header));
	SETIOV(iov + 1, &app_header, sizeof(app_header));
	SETIOV(iov + 2, payload, payload_size);
	printf("Client sending msg..\n");
	if (0 < MsgSendvs(server_coid, iov, 3, returnMsg, sizeof(returnMsg))) {
		perror("Cleint:MsgSend failed");
		exit(EXIT_FAILURE);
	}
	return 0;
}
int ExternDispatcher::server() {
	name_attach_t *attach;
	// Create a unique global name known within the network
	if ((attach = name_attach(NULL, ATTACH_POINT_SERVER, NAME_FLAG_ATTACH_GLOBAL))
			== NULL) {
		perror("Server: name_attach failed");
		return EXIT_FAILURE;
	}
	while (1) {
		// Waiting for a message and read first header
		header_t header;
		int rcvid = MsgReceive(attach->chid, &header, sizeof(header_t), NULL);
		if (rcvid == -1) { // Error occurred
			perror("Server: MsgReceived failed");
			break;
		}
		if (rcvid == 0) { // Pulse was received
			handle_pulse(header, rcvid);
			continue;
		}
		// continue while (1) loop
		// some sync msg was received
		if ((_IO_BASE <= header.type) && (header.type <= _IO_MAX)) {
			// Some QNX IO msg generated by gns was received
			handle_QNX_IO_msg(header, rcvid);
			continue;
		}
		// A sync msg (presumable ours) was received; handle it
		handle_app_msg(header, rcvid);
	}
	name_detach(attach, 0);
	return 0;
}
void ExternDispatcher::handle_pulse(header_t hdr, int rcvid) {
	switch (hdr.code) {
	case _PULSE_CODE_DISCONNECT:
		printf("Server received _PULSE_CODE_DISCONNECT\n");
		/* A client disconnected all its connections (called
		 * name_close() for each name_open() of our name) or
		 * terminated. */
		ConnectDetach(hdr.scoid);
		break;
	case _PULSE_CODE_COIDDEATH:
		printf("Pulse COIDDEATH received\n");
		break;
	case _PULSE_CODE_UNBLOCK:
		printf("Server received _PULSE_CODE_UNBLOCK\n");
		/* REPLY blocked client wants to unblock (was hit by
		 * a signal or timed out). It's up to you if you
		 * reply now or later. */
		break;
	case WERKSTUECK0:
		printf("PMSG Werkstueck 0 %d", hdr.value.sival_int);
		werk.tup=static_cast<ContextData::Werkstucktup>(hdr.value.sival_int);
		break;
	case WERKSTUECK1:
		printf("PMSG Werkstueck 1 %d", hdr.value.sival_int);
		werk.flipt = hdr.value.sival_int;
		break;
	case WERKSTUECK2:
		printf("PMSG Werkstueck 2 %d", hdr.value.sival_int);
		werk.heightSA1 = hdr.value.sival_int;
		break;
	case WERKSTUECK3:
		printf("PMSG Werkstueck 3: %d", hdr.value.sival_int);
		werk.heightSA1mean = hdr.value.sival_int;
		break;
	case WERKSTUECK4:
	{
		werk.id = hdr.value.sival_int;
		werk.heightSA2 = 0;
		uintptr_t werkPtrInt = uintptr_t(&werk);
		printf("id: %d, heightSA1: %d, heightSA1mean: %d, enum: %d", werk.id,
				werk.heightSA1, werk.heightSA1mean, (int) werk.tup);
		MsgSendPulse(this->dispatcherServer, PSMG_SW_WS_DATA,
		SIGEV_PULSE_PRIO_INHERIT, werkPtrInt);
	}
		break;
	default:
		MsgSendPulse(this->dispatcherServer, SIGEV_PULSE_PRIO_INHERIT, hdr.code,
				0);
		break;
	}
}
void ExternDispatcher::handle_QNX_IO_msg(header_t hdr, int rcvid) {
	if (hdr.type == _IO_CONNECT) {
// QNX IO msg _IO_CONNECT was received; answer with EOK
		printf("Server received _IO_CONNECT (sync. msg) \n");
		MsgReply(rcvid, EOK, NULL, 0);
		return;
	}
// Some other QNX IO message was received; reject it
	printf("Server received unexpected (sync.) msg type = 0x%04X\n", hdr.type);
	MsgError(rcvid, ENOSYS);
}

void ExternDispatcher::handle_app_msg(header_t hdr, int rcvid) {
	const char *ret_msg = "Got the message";
	if (DATA_MSG == hdr.type) {
		printf("Server: DATA_MSG not supported.\n");
		MsgError(rcvid, EPERM);
	} else if (STR_MSG == hdr.type) {
		printf("Server: STR_MSG received.\n");
// read app header
		app_header_t app_header;
		MsgRead(rcvid, &app_header, sizeof(app_header), sizeof(header_t));
// ToDo Check return value of MsgRead, in particular number of read bytes
// read payload
		char * buf = (char*) malloc(app_header.size);// ToDo check return value of malloc
		MsgRead(rcvid, buf, app_header.size,
				sizeof(header_t) + sizeof(app_header_t));
// ToDo Check return value of MsgRead, in particular number of read bytes
		printf("Server: got STR_MSG (count = %d): %s \n", app_header.count,
				buf);
		MsgReply(rcvid, EOK, ret_msg, strlen(ret_msg) + 1);		// send reply
		free(buf);
	} else { // Wrong msg type
		printf("Server: Wrong message type 0x%04X\n", hdr.type);
		MsgError(rcvid, EPERM);
	}
}

int ExternDispatcher::getchid() {
	return this->externChid;
}

void ExternDispatcher::sendWerkstueck(ContextData::werkstueck* werk) {
	printf("PMSG Werkstueck 0");
	if (-1
			== MsgSendPulse(this->server_coid, SIGEV_PULSE_PRIO_INHERIT,
					WERKSTUECK0, werk->tup)) {
		perror("Error sending pulse");
	}
	printf("PMSG Werkstueck 1");
	if (-1
			== MsgSendPulse(this->server_coid, SIGEV_PULSE_PRIO_INHERIT,
					WERKSTUECK1, werk->flipt)) {
		perror("Error sending pulse");
	}
	printf("PMSG Werkstueck 2");
	if (-1
			== MsgSendPulse(this->server_coid, SIGEV_PULSE_PRIO_INHERIT,
					WERKSTUECK2, werk->heightSA1)) {
		perror("Error sending pulse");
	}
	printf("PMSG Werkstueck 3");
	if (-1
			== MsgSendPulse(this->server_coid, SIGEV_PULSE_PRIO_INHERIT,
					WERKSTUECK3, werk->heightSA1mean)) {
		perror("Error sending pulse");
	}
	printf("PMSG Werkstueck 4");
	if (-1
			== MsgSendPulse(this->server_coid, SIGEV_PULSE_PRIO_INHERIT,
					WERKSTUECK4, werk->id)) {
		perror("Error sending pulse");
	}
	return;
}


void ExternDispatcher::startThread() {
	/*
#ifdef SIM_TWIN_B
		system("slay gns");
		system("gns -s");
#else
		system("slay gns");
		system("gns -c");
#endif */
	std::thread client(&ExternDispatcher::client, this);
	std::thread server(&ExternDispatcher::server, this);
	Dispatcher* dispatcher = Dispatcher::GetInstance();
	this->dispatcherServer = ConnectAttach(0, 0, dispatcher->getchid(),
	_NTO_SIDE_CHANNEL, 0);
	if (dispatcherServer == -1) {
		fprintf(stderr,
				"InterruptHandler: Error connecting to Dispatcher channel in Extern %d\n",
				errno);
		exit(1);
	}
	_pulse msg;
	while (1) {
		int rcvid = MsgReceivePulse(externChid, &msg, sizeof(_pulse), NULL);
		if (rcvid == -1){
			perror("Extern error receiving pulse");
			continue;
		}
		if(msg.code == PSMG_SW_WS_DATA){
			sendWerkstueck(reinterpret_cast<ContextData::werkstueck*>(msg.value.sival_int));
			continue;
		}
		if (rcvid != -1) {
			if (-1 == MsgSendPulse(this->server_coid, SIGEV_PULSE_PRIO_INHERIT, msg.code, 0)) {
				perror("Error sending pulse");
			}
		}

	}
	client.join();
	server.join();
	return;
}

