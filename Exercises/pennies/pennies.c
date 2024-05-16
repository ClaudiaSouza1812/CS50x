#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;
#include <math.h>

int main(void)
{
    float amount = get_float("Dolar amount: ");
    int pennies = round(amount * 100);
    printf("Pennies: %i\n", pennies);
}