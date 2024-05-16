#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //this counts the number of words typed in the terminal, if it
    //was 2, them will print the word designed in the array
    if (argc == 2)
    {
    //this command will take the arguments typed on the terminal
    //and print it considering the sequence of the array, so ./argv
    //is the first position, 0, and Claudia will be the second, 1.
    printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello World!\n");
    }

}