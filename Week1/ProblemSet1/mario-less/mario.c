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
        v = get_int("how tall you want this pyramid? ");
    }
    while (v < 1 || v > 8);


    //piramid builder, prompt the lines
    int i;
    //hashtag holder, prompt the columns
    int h;
    //space holder, prompt the columns
    int s;

    for (i = 0; i < v; i++)
    {
        for (s = v - 1; s > h; s--)
        {
            printf(" ");
        }
        for (h = 0; h <= i; h++)
        {
            printf("#");
        }

        printf("\n");
    }
}