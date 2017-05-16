#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char buffer[255];   // Buffer variable for user input

    //TODO:

    // Get the user's name with gets

    printf("Your name: ");
        scanf("%s", buffer);

    //TODO:

    // Print it out with puts
    printf("You are: ");
        puts(buffer);
        printf("\n");


    //TODO:

    // Get the user's pet name with getch
    printf("Your pet name?: ");

    int index = 0;
    char character = getch();
    while(character != 'r' ) {
        buffer[index] = character;
        index++;
        character = getch();
    }
    buffer[index] = 0;
        printf("Your pet name: ");
        puts(buffer);
    //TODO:

    // Print it out



    return 0;

}
