#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    //user imput
    int v;

    //user imput control
    do
    {
        v = get_int("how tall you want this pyramid? " );
    }
    while (v < 1 || v > 8);
    //print stored number
    printf("Stored: %i\n", v);

    //piramid builder, number of lines to print
    int i;
    //hashtag holder, number of hashtags to print in each line
    int h;

    for (i = 0; i < v; i++) //will execute the code bellow until the condition is reached
    {

        for (h = 0; h <= i; h++)
        {
            printf("#");
        }

        printf("\n");
    }

}