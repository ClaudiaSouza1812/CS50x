#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = 0;
    do
    {
        start = get_int("Starting population size: \n");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end = 0;
    do
    {
        end = get_int("Ending population size: \n");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int nb = 3;
    int np = 4;
    int i;

    for (i = 0; start < end; i++)
    {
        int born = start / nb;
        int pass = start / np;
        start = start + born - pass;
    }

    // TODO: Print number of years
    printf("Years: %i\n", i);
}
