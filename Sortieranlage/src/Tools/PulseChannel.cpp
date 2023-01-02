

#include "PulseChannel.h"



PulseChannel::PulseChannel() {
	chid = ChannelCreate(0);
	if(chid == -1){
		perror("Create PulseChannel failed\n");
		exit(-1);
	}
}

PulseChannel::~PulseChannel() {
	ChannelDestroy(chid);
}

int PulseChannel::getChannelId(void){
	return chid;
}

struct _pulse PulseChannel::Msg_ReceivePulse(void){
	struct _pulse pulse;
	if(0 != MsgReceivePulse(chid,&pulse,sizeof(pulse),NULL))
	{
		fprintf(stderr,"errno = %s",strerror(errno));
		exit(-1);
	}

	return pulse;
}
