#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;

int main(void)
{
    const int MINE = 2;
    int points = get_int("How many points did you lose? ");

    if (points < MINE)
    {
        printf("You lost fewer points than me. \n");
    }
    else if (points > MINE)
    {
       printf("You lost more points than me. \n");
    }
    else
    {
        printf("You lost the same number of points as me. \n");
    }
}