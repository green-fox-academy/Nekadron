#include <stdio.h>
#include <stdlib.h>
//TODO:
// print the value of number using the "number_pointer"
int main()
{
    int number = 1234;
    int *number_pointer = &number;

    printf("%d", *number_pointer);

    return 0;
}
