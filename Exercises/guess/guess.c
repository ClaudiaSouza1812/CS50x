#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number = 5;

    int guess = get_int("Whats your guess? \n");

    if (guess != number)
    {
        printf("wrong guess \n");
    }
    else
    {
        printf("you're correct! \n");
    }
}