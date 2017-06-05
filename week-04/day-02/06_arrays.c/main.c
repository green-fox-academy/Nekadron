#include <stdio.h>
#include <stdlib.h>
//TODO:
// The "number_pointer" should point to the first element of the array called "numbers",
// than please print its value with it.

int main()
{
    int numbers[] = {5, 6, 7, 8, 9};
    int *number_pointer = numbers;

        printf("%d", number_pointer[0]);


    return 0;
}
