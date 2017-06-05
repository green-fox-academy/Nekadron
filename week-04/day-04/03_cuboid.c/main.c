#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};
// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
int GetSurface(struct(rectangular_cuboid var))
{
    return (2 * var.a * var.b + 2 * var.a * var.c + 2 * var.b * var.c);           //surface area is 2(ab + ac + bc)
}
// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
int GetVolume(struct(rectangular_cuboid var))
{
    return (*var.a * var.b * var.c);                // cuboid   l = length, w = width, h = height
}
int main()
{
    var.a = 4;
    var.b = 2;
    var.c = 3;

   struct rectangular_cuboid var = {2, 2, 2};
    printf("Surface: %d\nVolume: %d", GetSurface(var), GetVolume(var));


    return 0;
}
