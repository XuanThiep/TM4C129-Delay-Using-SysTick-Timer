#include <stdbool.h>
#include <stdint.h>
#include "driverlib/inc/hw_memmap.h"
#include "driverlib/inc/hw_types.h"
#include "driverlib/inc/hw_nvic.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "mytm4c129.h"

/* Declaring Global Variables */
volatile uint32_t sys_clock_hz;



/* Declaring Function Prototype */




int main(void)
{
	/* Configure system clock using external clock and PLL */
	sys_clock_hz = MAP_SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN |
			SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480,
			120000000);
	SysTick_For_Delay_Init(sys_clock_hz);

	/* Enable GPIO Peripheral Clock */
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

	/* Configure Led as gpio output */
	MAP_GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 );

	/* Infinite Loop */
	while(1)
	{
		MAP_GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 ,0xff);
		Delay_ms(70);
		MAP_GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 ,0x00);
		Delay_ms(1000);
	}
}



