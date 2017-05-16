#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void safeUnion(int *a, int l_a, int *b, int l_b, int *result, int l_res) {

    //TODO:

    // Implement this function to create the union of a and b into the array result!

    return;
    int i;
    int k;
    for(i = 0; i < l_a; i++){
        result [i] = a[i];
    }
    for(k = 0; k < l_b; k++){
        result[k+i] = b[k];
    }
}
int main(int argc, char** argv) {

    int a[3] = {1,2,3};

    int b[3] = {4,5,6};

    int c[6];
    int i;
    safeUnion(a,3,b,3,c,6);

    for (i = 0; i<6; i++) {

        printf("%d\n", c[i]);

    }

    return 0;

}
