#include "freq_meas.h"
#include "UART_driver.h"
#include "AC_driver.h"
#include "ADC_driver.h"
#include "IncFile1.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <util/delay.h>

void init_pwm()
{
	// PD6 is now an output
	DDRB |= 1 << DDRB3;
	
	// set none-inverting mode
	TCCR2A |= (1 << COM2A1);
	
	//TODO:
	//Write a function which initializes the TC0 timer in Fast PWM mode
	TCCR2A |= (1 << WGM20);
	TCCR2A |= (1 << WGM21);
	
	// set prescaler to 8 and starts PWM
	TCCR2B |= (1 << CS22) | (1 << CS20);
	
}

void system_init()
{
	init_pwm();
	//i need to call the ADC_init caus the potmeter
	ADC_init();
	AC_driver_init();
	freq_meas_init();
	UART_init();
	sei();
}

void wait()
{
	_delay_ms(100);
}

int main(void)
{
	system_init();
	
	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM((void *)UART_send_character, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, (void *)UART_get_character, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP
	
	// Try printf
	printf("Startup...\r\n");
	
	float ref = 4300;
	float process_variable = get_freq();
	float err = 0;
	float ctrler_out;
	float ctrler_out_min = 0;
	float ctrler_out_max = 5000;
	float P = 2;
	
	while (1)
	{
		err = ref - process_variable;
		ctrler_out = P * err;

		if (ctrler_out < ctrler_out_min) {
			ctrler_out = ctrler_out_min;
			printf("%f\nctrler_out",ctrler_out);
		}
		else if (ctrler_out > ctrler_out_max) {
			ctrler_out = ctrler_out_max;
			printf("ctrler_out%f\n",ctrler_out);
		} else {
		}
		
		
		wait();
	
		// i need to divide with 4 cause the adc 1023 and the OCR0A is 255
		// if i don't divide than the data overflow !!!
		OCR2A = ADC_read() / 4;
				
		printf("%f Hz\n", get_freq());
		printf("%f RPM\n", get_rpm());
	}
}