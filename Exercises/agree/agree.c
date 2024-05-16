#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;

int main(void)
{
    // prompt user to agree
    char c = get_char("Do you agree? ");

    // check whether user agreed
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }

}