#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

// TODO:
// Write the interrupt handlers

volatile uint16_t vect_overflow;
volatile uint16_t prev;
volatile uint16_t last;
volatile uint16_t mem;
volatile uint16_t counter_max = 65535;

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	

	//Input Capture Interrupt Enable
	TIMSK1 |= (1 << ICIE1);
	
	//Overflow Interrupt Enable
	TIMSK1 |= (1 << TOIE1);
	
	//prescaler
	TCCR1B = 0b100;

	// enable interrupts
	sei();
}

// TODO:
// Write this function. It returns the measured frequency in Hz
ISR(TIMER1_OVF_vect)
{
	vect_overflow++;	
};

ISR(TIMER1_CAPT_vect)
{
	prev = last;
	last = ICR1;
	mem = vect_overflow;
	vect_overflow = 0;
};

float get_freq()
{
	
	float T;
	float f;
	uint16_t steps;
	float Tclk = 1 / (float) 16000000;
	
	steps = mem * counter_max + last - prev;
		if (steps == 0) {
		return 0;
		}
	T = 256 * Tclk * steps;
	
	f = 1 / T;
	
	return f;
}