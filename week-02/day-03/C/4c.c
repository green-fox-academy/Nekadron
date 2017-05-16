#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Write a non void function which has a paramters (let's say for example x).

The funtion than returns the "xth" fibonaci number.

What the hack is a fibonacci number? Search it on wikipedia!

*/

    int fib(int);

int main(){

    int xth = fib(18);
        printf("%d", xth);

    return 0;
}
    int fib(int x){
        if(x <= 1);
            return x;
                return fib(x - 1) + fib(x -2);
    }
