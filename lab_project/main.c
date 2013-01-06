/*
 * main.c
 */

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

void main(void) {

	unsigned long ulPeriod, DELAY;

	DELAY = 1000000;

	// 50Mhz off pll driven by ext 16mhz xtal
	SysCtlClockSet(
			SYSCTL_SYSDIV_2 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
					| SYSCTL_OSC_MAIN);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);

	TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM);

	// Configure PF2 as T1CCP0, so blue led become PWM driven
	GPIOPinConfigure(GPIO_PF2_T1CCP0);
	GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_2);

	unsigned long base_freq = 500; // 500Hz

	unsigned long ulP_ticksForFreq = (SysCtlClockGet() / base_freq);

	TimerLoadSet(TIMER1_BASE, TIMER_A, ulP_ticksForFreq - 1);

	TimerEnable(TIMER1_BASE, TIMER_A);

	while (1) {

		TimerMatchSet(TIMER1_BASE, TIMER_A, 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod / 10) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 25 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 33 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 50 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 66 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 75 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 75 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 66 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 50 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 33 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod * 25 / 100) - 1);
		SysCtlDelay(DELAY);

		TimerMatchSet(TIMER1_BASE, TIMER_A, (ulPeriod / 10) - 1);
		SysCtlDelay(DELAY);

	}

}
