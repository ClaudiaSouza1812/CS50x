#include <stdio.h>
#include <cs50.h>

int factorial(int number);

int main(void)
{
    int n = get_int("Type a number: ");
    printf("%i\n", factorial(n));
}


int factorial(int number)
{
    //base case;
    if (number == 1)
    {
        return 1;
    }
    //factorial will be called until reaches the base case;
    return number * factorial(number - 1);
}