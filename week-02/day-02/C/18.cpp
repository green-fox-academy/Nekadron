#include <stdio.h>
#include <stdint.h>

int main() {

	uint16_t number = 254;
	if(number > 255){
    printf("longer than 8bits");
	}

	// if number can't be represented with 8bits

	// print 'longer than 8bits' otherwise print 'ok'

	return 0;

}
