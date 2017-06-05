#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */
int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';

    int *number_pointer = &number;
    float *Pi_pointer = &Pi;
    char *letter_pointer = &letter;

    printf("%p       \t%p\t%p\n", number_pointer, Pi_pointer, letter_pointer);
    printf("%d       \t%f\t%c\n", number, Pi, letter);
    printf("%p       \t%p\t%p\n", &number, &Pi, &letter);
    printf("%d       \t%f\t%c\n", number, Pi, letter);


    return 0;
}
