#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;

} Point;

// TODO:
// Create a function the constructs a Point (returns a pointer to a new point)
// It should take it's x and y coordinate as parameter

Point* CreatPoint(int x, int y)
{
    Point* point = (Point*)malloc(sizeof(Point));
    point->x = x;      //pointerem rámutat az x-re és így tudja majd meghívni a fügvényből.
    point->y = y;      //pointerem rámutat az y-ra és így tudja majd meghívni a fügvényből.
    return point;
}


// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them
float Distance(Point* point1, Point* point2)                //Distance = gyök alatt az egész(x2−x1)2+(y2−y1)2
{
    float distance = sqrt(pow(point1->x - point2->x, 2) + pow(point1->y - point2->y, 2));

    return distance;
}

int main()
{
    Point* point1 = CreatPoint(1, 1);
    Point* point2 = CreatPoint(2, 2);
    float distance = Distance(point1, point2);

    printf("%f", distance);

    return 0;
}
