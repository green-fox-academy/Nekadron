#include <stdio.h>
#include <stdlib.h>
//TODO:
// update the value of number variable to 42 using the "number_pointer"
int main()
{
    int number = 1234;
    int *number_pointer = &number;

    number_pointer = 42;
    printf("%d", number_pointer);

    return 0;
}
