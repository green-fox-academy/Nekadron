#include <stdio.h>
#include <stdlib.h>
//TODO:
// Please fix the problem and swap where the pointers point,
// without using the "&" operator.

int main()
{
    int high_number = 6655;
    int low_number = 2;


    int *hight_number_pointer = &low_number;
    int *low_number_pointer = &high_number;

    printf("%d\t", hight_number_pointer);
    printf("%d", low_number_pointer);



    return 0;
}
