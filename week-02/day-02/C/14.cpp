#include <stdio.h>
#include <stdint.h>

int main() {

    uint8_t number = 254;

	uint8_t result;

    result = number + 23;
    printf("%d\n", result);

	// Check the result with printf

 	// What happened?!

	// Try again with different datatype
	 uint16_t result_16 = number + 23;
     printf("%d\n", result_16);
	// Check the result with printf



	// What happened and why?



	//----------------------------------------

	int8_t number_negative = number;
    printf("%d\n", number_negative);
	// Check the result with printf



	// What happened and why?

    return 0;

}
