#include <stdio.h>
#include <stdlib.h>
/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
int main()
{
    char dest[] = "Hi ";
    char source[] = "man!";
    char result[100];
    int i;
    int a;

    for (i = 0; dest[i] != '\0'; i++) {
        result[i] = dest[i];
    }
    for (a = 0; source[a] != '\0'; a++) {
        result[a + i] = source[a];
    }
    result[i + a] = '\0';

    puts(result);



    return 0;
}
