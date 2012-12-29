/*
 * main.c
 */

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "softPwm.h"

// delay before a new PWM value is set
// SysCtlDelay() loop is 3 clocks
#define DELAY 2000000

void main(void) {

	// 50Mhz off pll driven by ext 16mhz xtal
	SysCtlClockSet(
			SYSCTL_SYSDIV_2 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
					| SYSCTL_OSC_MAIN);

	// activate blue LED gpio
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

	// clear any existing state
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);

	softPwmInit();

	unsigned long base_freq = 500; // 500Hz

	while (1) {

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 0);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 10);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 25);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 33);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 50);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 66);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 75);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 100);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 75);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 66);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 50);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 33);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 25);
		SysCtlDelay(DELAY);

		softPwmConfig(GPIO_PORTF_BASE, GPIO_PIN_2, base_freq, 10);
		SysCtlDelay(DELAY);

	}

}
