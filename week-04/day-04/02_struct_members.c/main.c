#include <stdio.h>
#include <stdint.h>

struct computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};
//TODO: Change the bits to 64
//TODO: print out the structure members
int main()
{
    struct computer comp = {3.2, 8, 32};

    comp.bits *= 2;
    printf("%d", comp.bits);

    return 0;
}
