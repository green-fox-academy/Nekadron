#include <stdio.h>
#include <stdlib.h>
// TODO:
// Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
// Please delete the array before the program exits
int main()
{
    int* pointer = NULL;
    int i;

    int a[] = {'0', '1', '2', '3', '4'};

    for (i = 0; i < 5; i++)
        printf("%d\n", i);

    return 0;
}
