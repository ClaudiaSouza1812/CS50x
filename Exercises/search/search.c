#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    int c = 0;
    
    for (int i = 0; i == c; i++)
    {
        if (strings[i] != 0)
        {
            c++;
        }
    }

    string s = get_string("Your guess: ");
    for (int j = 0; j < c; j++)
    {
        if (strcmp(strings[j], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}