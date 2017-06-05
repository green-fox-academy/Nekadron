#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Add two numbers using pointers

*/
int main()
{

    int a  = 20;
    int b = 17;

    int *a_pointer = &a;
    int *b_pointer = &b;

    *a_pointer += 2;
    *b_pointer += 2;

    printf("%d--------------%d", a, b);


    return 0;
}
