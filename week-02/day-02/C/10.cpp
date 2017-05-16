#include <stdio.h>

int main() {

	int j1 = 10;

	int j2 = 3;
    int a = j2 * j2;
    int b = j2 * j2 * j2;
    int c = (j1 > a) && (j1 < b);
    printf("%d" , c );
	// tell if j1 is higher than j2 squared and smaller than j2 cubed

	return 0;

}
