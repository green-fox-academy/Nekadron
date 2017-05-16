#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Write a void function which has two float parameters. The function can do the

totoro operation on those parameters and it also prints out the result of the operation

on the screen.



The totoro operation does the following on two variables (let's say we have "a"

 and "b")

result = a*b+(a+b)+a*a*a+b*b*b+3.14159265358979

*/

int main(){

    float a = 7.00;

    float b = 10.00;

    TotoroOperation(a, b);

    return 0;
}

void TotoroOperation(float a, float b){
    printf("%f", a * b + (a+b) + a * a * a + b * b * b + 3.14159265358979);

}
