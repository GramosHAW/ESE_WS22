#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "../HAL/InterruptHandler.h"
#include <sys/neutrino.h>
#include <mutex>
using namespace std;

class Dispatcher {
private:
	int fsmchid;
	int adcChid;
	//int channelIDhal;
	int connectionIdHalAktorik;
	bool run_thread;
	static std::mutex mutex_;
	static Dispatcher* m_pInstance;
	struct sigevent event;
	void handelHALpuls();
	//Chanel fure der Dispatcher
	int dispatcherChannelId;
protected:

public:

	Dispatcher();
	~Dispatcher();
	std::string value_;

	/**
	 * Singletons should not be cloneable.
	 */
	Dispatcher(Dispatcher &other) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(const Dispatcher &) = delete;
	/**
	 * This is the static method that controls the access to the singleton
	 * instance. On the first run, it creates a singleton object and places it
	 * into the static field. On subsequent runs, it returns the client existing
	 * object stored in the static field.
	 */

	/**
	 * Finally, any singleton should define some business logic, which can be
	 * executed on its instance.
	 */
    static Dispatcher *GetInstance();
	std::thread * isr_thread;

	void start_HAL_PulsResiver_THREAD(void);
	//geta für den Channel für PulseMessages
	int getchid();
	void set_FSM_chid(int fsmChid);
	void set_ADC_chID(int adcChid);
};
#endif
