#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Write a non void function which returns the value of PI, so the following number:

3.14159



Try it out in the main function by printing out the result of the pi generator function!

*/
double PiGenerator(void);

int main(){

    double result = PiGenerator();
        printf("%f", result);


    return 0;

}
double PiGenerator(void){

    return 3.14159;
}
