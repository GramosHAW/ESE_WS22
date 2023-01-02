

#ifndef SRC_HAL_GPIO_H_
#define SRC_HAL_GPIO_H_

//#include "../utilities.h"
#include <iostream>
//#include "Sortieranlage.h"
#include <stdio.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "Aktorik.h"

#define GPIO0_BASE_ADRESS		(0x44E07000)
#define GPIO1_BASE_ADRESS		(0x4804C000)
#define GPIO2_BASE_ADRESS		(0x481AC000)
#define GPIO_CTRL_Register		(0x00000130)
#define GPIO_CLOCK_ENABLE		(0x00000001)// Gate Clocks
#define GPIO_OE_Register		(0x00000134) // used to enable the pins in/out capabilities. Default 0xFFFFFFFF (All pins as Output)
#define GPIO_DATAIN_Register    (0x00000138)
//#define GPIO_CLEARDATAOUT       (0x00000190)
//#define GPIO_SETDATAOUT		  (0x00000194)
#define GPIO_DATAOUT_Register	(0x0000013C)


#define GPIO_SYSCONFIG      	0x10
#define GPIO_IRQSTATUS_RAW_0	0x24 //(Reset 0)
#define GPIO_IRQSTATUS_RAW_1	0x28 //(Reset 0)
#define GPIO_IRQSTATUS_0		0x2C //(Reset 0)
#define GPIO_IRQSTATUS_1 		0x30 // 1h(W) = Clears the IRQ; 1h(R) = IRQ is triggered (Reset 0)
#define GPIO_IRQSTATUS_SET_0	0x34 //
#define GPIO_IRQSTATUS_SET_1	0x38 // Writing a 1 enables IRQ generation for the pin (Reset 0)
#define GPIO_IRQSTATUS_CLR_0	0x3C // Writing a 1 disables IRQ generation
#define GPIO_IRQSTATUS_CLR_1	0x40 // Writing a 1 disables IRQ generation
#define GPIO_LEVELDETECT0		0x140 // Low level detection
#define GPIO_LEVELDETECT1		0x144 // high level detection
#define GPIO_RISINGDETECT		0x148 // an 1 enables IRQ on rising-edge and an 0 disable it
#define GPIO_FALLINGDETECT		0x14C // an 1 enables IRQ on falling-edge and an 0 disable it
#define GPIO_DEBOUNCENABLE      0x150
#define GPIO_DEBOUNCINGTIME     0x154


class GPIO{
private:
	uintptr_t port_adress;
public:
	GPIO(uintptr_t adress);
	virtual ~GPIO();
	uint32_t EnableClock();
	uint32_t SysConfig(uint32_t mask);
	uint32_t PortAsInput();
	uint32_t PortAsOuput();
	uint32_t ReadDataIn();
	uint32_t ClearDataOut(uint32_t mask);
	uint32_t SetDataOut(uint32_t mask);
	uint32_t EnableIRQ_0(uint32_t mask);
	uint32_t EnableIRQ_1(uint32_t mask);
	uint32_t EnableRISINGDETECT(uint32_t mask);
	uint32_t EnableFALLINGDETECT(uint32_t mask);
	uint32_t LowlevelDetect(uint32_t mask);
	uint32_t HighlevelDetect(uint32_t mask);
	uint32_t GetIRQSTATUS_0(void);
	uint32_t GetIRQSTATUS_1(void);
	uint32_t ClearIRQ_0(uint32_t mask);
	uint32_t ClearIRQ_1(uint32_t mask);
	uint32_t DisableIRQ_0(uint32_t mask);
	uint32_t DisableIRQ_1(uint32_t mask);
	uint32_t EnableDEBOUNCING(uint32_t mask);
	uint32_t SetDEBOUNCINGTIME(uint32_t mask);
};

#endif /* SRC_HAL_GPIO_H_ */
