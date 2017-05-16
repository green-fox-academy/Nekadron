#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char char_array[] = {'a', 'b', 'c', 'd'};

    char char_array_the_same[] = "abcd";

    int i;

    for(i = 0; i < 4; i++){
        printf("%c\n", char_array[i]);
    }

    for(i = 0; i < 4; i++){
        printf("%c", char_array_the_same[i]);
    }
	//TODO:

    // Print out the two arrays character-by-character



	//TODO:

    // What is the difference between the arrays?



    return 0;

}
