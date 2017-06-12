#define F_CPU 16000000

#include "ADC_driver.h"
#include <stdio.h>
#include <avr/io.h>
#include <avr/delay.h>
//#include "UART_driver.h"
//#include <avr/interrupt.h>

void init_pwm()
{
	// PD6 is now an output
	DDRD |= 1 << DDD6;
	
	// set PWM for 50% duty cycle

	
	// set none-inverting mode
	TCCR0A |= (1 << COM0A1);
	
	//TODO:
	//Write a function which initializes the TC0 timer in Fast PWM mode
	TCCR0A |= (1 << WGM00);
	TCCR0A |= (1 << WGM01);
	
	// set prescaler to 8 and starts PWM
	TCCR0B |= (1 << CS02) | (1 << CS00);
	//TODO:
	//Write a function which sets the duty cycle (0-100) of the PWM signal on the OC0A pin
	//The function should have one uint8_t parameter which value is between 0-100
	
}
	
/*void set_pwm_output(uint8_t brhightness)
{	//here i need to change the OCR0A value to 100
	//because the OCR0A value is 255 (8 bit)
	OCR0A = (brhightness / 100) * 255;
}*/
	
/*void wait()
{
	_delay_ms(100);
}*/
int main(void)
{	
	init_pwm();
	//i need to call the ADC_init caus the potmeter
	ADC_init();

	
	while (1)
	{
	//	uint8_t brhightness;
	
		// i need to divide with 4 cause the adc 1023 and the OCR0A is 255
		// if i dont divide than the data overflow !!!
		OCR0A = ADC_read() / 4;
		//wait();
		
		
		/*
		// The for cycle just vithout the WHILE!!!!!
		for (brhightness = 0; brhightness < 255; brhightness++) {
			set_pwm_output(brhightness);
			printf("Bright: %d\n", brhightness);
			wait();
		}
		
		for (brhightness = 255; brhightness > 0; brhightness--) {
			set_pwm_output(brhightness);
			printf("Bright -: %d\n", brhightness);
			wait();
		}*/
	}
    return 0;
}

