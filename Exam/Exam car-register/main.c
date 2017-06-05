#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */
enum transmission {manual, automatic, semi-automatic, CVT, dual-clutch};

 struct Cars{
    char type[255];
    int year of manufacture;
    float price;
    enum transmission;
};


void main() {




