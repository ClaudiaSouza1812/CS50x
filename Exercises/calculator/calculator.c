#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;

int main(void)
{
    //prompt user for x
    float x = get_float("x: ");

    //prompt user for y
    float y = get_float("y: ");

    // divide x by y
    float z = x / y;

    //perform addition
    printf("%.20f\n", z);
}