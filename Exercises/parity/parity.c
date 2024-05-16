#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;

int main(void)
{
    int n = get_int("n: ");

    // if n is divisible by 2, it is even
    if (n % 2 == 0)
    {
        printf("even\n");
    }
    // if n is not, is odd
    else
    {
        printf("odd\n");
    }
}