#include <stdio.h>
#include <stdlib.h>
//#define TOTORO 19
// Define the TOTORO macro which holds the number of students in our class

int main()
{
    // Use the #ifdef and #ifndef macros!
    // If the TOTORO macro is not defined print out 32
    // If the TOTORO macro is defined print out it's value
    #ifdef TOTORO
    printf("Totoro class member count:\t%d", TOTORO);
    #endif
    #ifndef TOTORO
    printf("Totoro class member count:\t%d", 32);
    #endif // TOTORO
    return 0;

}




