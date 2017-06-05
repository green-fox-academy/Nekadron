#include <stdio.h>
#include <stdlib.h>
//TODO:
// The "number_pointer" should point to the third element of the array called "numbers",
// than please print its value with it. Solve the problem without reusiong the "&" operator
// for geting the address of the third element.
int main()
{
    int numbers[] = {5, 6, 7, 8, 9};
    int* number_pointer = &numbers[0];
    int i;

    printf("%d\n", numbers[2]);

    number_pointer += 2;

    printf("%x", number_pointer);

    return 0;
}
