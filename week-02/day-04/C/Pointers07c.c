#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int high_number = 6655;

    int low_number = 2;



    int* hight_number_pointer = &low_number;

    int* low_number_pointer = &high_number;

    //TODO:
    int *x_pointer = hight_number_pointer;
    hight_number_pointer = low_number_pointer;
    low_number_pointer = x_pointer;
    // Please fix the problem and swap where the pointers point,
    printf("%d\n", *hight_number_pointer);
    printf("%d\n", *low_number_pointer);

    // without using the "&" operator.



    return 0;

}
