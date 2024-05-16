#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    //integer variable with a true value;
    int prime = true;
    //loop that will check the number until its reaches the limit;
    for (int i = 2; i < number; i++)
        //a condition that will check if % (modulo, rest) of number is 0, if it is, the number
        //isin't prime, because prime numbers always has a rest, so the value of variable
        //prime will be changed to false;
    {
        if (number % i == 0)
        {
            prime = false;
            break;
        }
    }
    //number receive the value of prime;
    number = prime;

    return number;
}

