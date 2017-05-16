/*
 * w3d1.c
 *
 * Created: 2017.05.15. 15:11:10
 * Author : Nekadron
 */ 

#include <avr/io.h>
#include <avr/interrupt.h> 
#define F_CPU 16000000
#include <util/delay.h>




void init(){

	DDRD |= (1 << DDRD0);
	DDRD |= (1 << DDRD1);
	DDRD |= (1 << DDRD2);



}

int main(void)

{
	init();
	while(1){

		for(int i = 0; i < 3; i++){
			PIND = 1 << i;
			_delay_ms(100);
			PIND &=~ 1 << i;
			_delay_ms(100);
		}
	}
}
