#include <iostream>
//#include "HAL/Aktorik.h"
//#include "Sortieranlage.h"
#include <stdio.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <iostream>
#include <thread>
#include <chrono>
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

#include "GPIO.h"

GPIO::GPIO(uintptr_t adress){
	port_adress = adress;
}

GPIO::~GPIO(){

}

uint32_t GPIO::SysConfig(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_SYSCONFIG),mask);
	return in32((uintptr_t) (port_adress + GPIO_SYSCONFIG));
}


/**
 * Enable the GPIO Clock
 * @return The Status of the GPIO Control Register
 */
uint32_t GPIO::EnableClock(){

	out32((uintptr_t) (port_adress + GPIO_CTRL_Register),GPIO_CLOCK_ENABLE);
	return in32((uintptr_t) (port_adress + GPIO_CTRL_Register));
}

/*
 * Set the Port as Input
 * @return The state of GPIO_OE register, which is used to enable the pins output capabilities.
 * All pins set to 1 are configured as input.At reset,all the GPIO related pins are configured
 * as input and output capabilities are disabled
 */
uint32_t GPIO::PortAsInput(){

	out32((uintptr_t) (port_adress + GPIO_OE_Register),0xFFFFFFFF);
	return in32((uintptr_t) (port_adress + GPIO_OE_Register));
}

/*
 * Set the Port as Output
 * @return The state of GPIO_OE register, which is used to enable the pins output capabilities.
 * All pins set to 1 are configured as input.At reset,all the GPIO related pins are configured
 * as input and output capabilities are disabled
 */
uint32_t GPIO::PortAsOuput(){
	out32((uintptr_t) (port_adress + GPIO_OE_Register),0x0000000);
	return in32((uintptr_t) (port_adress + GPIO_OE_Register));
}

/**
 * @return the Data, that is read from the GPIO pins
 */
uint32_t GPIO::ReadDataIn(){

	return in32((uintptr_t) (port_adress + GPIO_DATAIN_Register));
}

/**
 * Clear GPIO pins
 * @param Mask of the pins that have to be cleared. Pins set to 1 in the Mask will be cleared
 * @return Status of the GPIO pins
 */
uint32_t GPIO::ClearDataOut(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_CLEARDATAOUT),mask);
	return in32(port_adress+GPIO_DATAIN_Register);
}

/**
 * Set GPIO pins
 * @param Mask of the pins that have to be set. Pins set to 1 in the Mask will be set
 * @return Status of the GPIO pins
 */
uint32_t GPIO::SetDataOut(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_SETDATAOUT),mask);
	return in32(port_adress+GPIO_DATAIN_Register);
}

/**
 * Enable IRQ generation for all pins set to 1 in the mask.
 * @param mask Mask of the related pins.
 * @return The Status of the IRQ Status Register
 */
uint32_t GPIO::EnableIRQ_0(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_IRQSTATUS_SET_0),mask);
	return in32(port_adress+GPIO_IRQSTATUS_0);
}

/**
 * Enable IRQ geberatio for all pins set to 1 in the mask.
 * @param mask Mask of the related pins.
 * @return The Status of the IRQ Status Register
 */
uint32_t GPIO::EnableIRQ_1(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_IRQSTATUS_SET_1),mask);
	return in32(port_adress+GPIO_IRQSTATUS_1);
}

/**
 * Disable IRQ generation for Pins
 * @param mask Mask of the related pins.Writing 1 for a pin disables the IRQ generation for this pin.
 * @return The Status of the IRQ Status Register
 */
uint32_t GPIO::DisableIRQ_0(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_IRQSTATUS_CLR_0),mask);
	return in32(port_adress+GPIO_IRQSTATUS_0);
}

/**
 * Disable IRQ generation for Pins
 * @param mask Mask of the related pins.Writing 1 for a pin disables the IRQ generation for this pin.
 * @return The Status of the IRQ Status Register
 */
uint32_t GPIO::DisableIRQ_1(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_IRQSTATUS_CLR_1),mask);
	return in32(port_adress+GPIO_IRQSTATUS_1);
}


/**
 * Enable the rising detection for the related pins
 * @param mask of the related pins
 * @return State of the GPIO_RISINGDETECT Register
 */
uint32_t GPIO::EnableRISINGDETECT(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_RISINGDETECT),mask);
	return in32(port_adress+GPIO_RISINGDETECT);
}

/**
 * Enable the Falling detection for the related pins
 * @param mask of the related pins
 * @return State of the GPIO_FALLINGDETECT Register
 */
uint32_t GPIO::EnableFALLINGDETECT(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_FALLINGDETECT),mask);
	return in32(port_adress+GPIO_FALLINGDETECT);
}

/**
 * Enable  Low-level detection for the related pins
 * @param mask of the related pins. Writing 1 enables the low-level detection and 0 disable it
 * @return State of the GPIO_LEVELDETECT0 Register
 */
uint32_t GPIO::LowlevelDetect(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_LEVELDETECT0),mask);
	return in32(port_adress+GPIO_LEVELDETECT0);
}

/**
 * Enable  High-level detection for the related pins
 * @param mask of the related pins. Writing 1 enables the High-level detection and 0 disable it
 * @return State of the GPIO_LEVELDETECT1 Register
 */
uint32_t GPIO::HighlevelDetect(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_LEVELDETECT1),mask);
	return in32(port_adress+GPIO_LEVELDETECT1);
}


/**
 * @return all triggered IRQ
 */
uint32_t GPIO::GetIRQSTATUS_0(void){

	return in32(port_adress+GPIO_IRQSTATUS_0);
}


/**
 * @return all triggered IRQ
 */
uint32_t GPIO::GetIRQSTATUS_1(void){

	return in32(port_adress+GPIO_IRQSTATUS_1);
}

/**
 * Clear the IRQ for pins. Writing an 1 clears the IRQ for the related pin.
 * @param mask of the related pins
 * @return the State of the GPIO_IRQSTATUS Register
 */
uint32_t GPIO::ClearIRQ_0(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_IRQSTATUS_0),mask);
	return in32(port_adress+GPIO_IRQSTATUS_0);
}

/**
 * Clear the IRQ for pins. Writing an 1 clears the IRQ for the related pin.
 * @param mask of the related pins
 * @return the State of the GPIO_IRQSTATUS Register
 */
uint32_t GPIO::ClearIRQ_1(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_IRQSTATUS_1),mask);
	return in32(port_adress+GPIO_IRQSTATUS_1);

}




/**
 * Enable/Disable the debouncing feature for each GPIO
 * @param mask of the related pins. Writing 1 enable the feature for the pin and 0 disable it.
 * @return the state of the GPIO_DEBOUNCENABLE register
 */
uint32_t GPIO::EnableDEBOUNCING(uint32_t mask){

	out32((uintptr_t) (port_adress + GPIO_DEBOUNCENABLE),mask);
	return in32(port_adress+GPIO_DEBOUNCENABLE);
}

/**
 * Configure the debouncing time.The debouncing cell is running with the debouncing clock(32 kHz)
 * @param mask: number of the clock cycle(s). 0<=mask<=255 .
 * DebouncingValue = (DEBOUNCETIME + 1) * 31 microseconds
 * @return the current debouncing time.
 */
uint32_t GPIO::SetDEBOUNCINGTIME(uint32_t mask){

	if(mask>255 || mask<0)
	{
		fprintf(stderr,"Invalid value for debouncing-time");
		exit(-1);
	}
	out32((uintptr_t) (port_adress + GPIO_DEBOUNCINGTIME),mask);
	return in32(port_adress+GPIO_DEBOUNCINGTIME) & 0x000000FF;
}
