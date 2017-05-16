#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int high_number = 2;

    int low_number = 6655;



    int* hight_number_pointer = &high_number;

    int* low_number_pointer = &low_number;

    //TODO:
    int *x_pointer =low_number_pointer;
    low_number_pointer = hight_number_pointer;
    hight_number_pointer = x_pointer;
    // Please fix the problem and swap the value of the variables,
    printf("%d\n", high_number);
    printf("%d\n", low_number);
    // without using the "high_number" and the "low_number" variables.



    return 0;

}
