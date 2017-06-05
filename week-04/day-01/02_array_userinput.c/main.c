#include <stdio.h>          //ATLAGOT SZAMOLO PROGI//
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.
int main()
{
    int buffer;
    int i;
    int a = 0;
    int b;
    int *pointer;

    printf("Give me a number: ");
    scanf("%d", &buffer);
    printf("%d ", buffer);

    pointer = (int*)calloc(buffer, sizeof(int));

    for (i = 0; i < buffer; i++) {
        printf("Give me another number: ");
        scanf("%d", &b);
        a = a + b;
    }
    printf("Average: %f", (float) a/buffer);

    free(*pointer);
    return 0;
}
