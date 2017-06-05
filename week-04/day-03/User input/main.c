#include <stdio.h>
#include <stdlib.h>
/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/
int main() {

    char buffer[255];
    int buff;
    int i;
    int a = 100;

    printf("Give me your name: ");
    scanf("%s", &buffer);

    printf("Give me your age: ");
    scanf("%d", &buff);

    printf("You will be an old fart after %d years: ", a - buff);

    return 0;
}
