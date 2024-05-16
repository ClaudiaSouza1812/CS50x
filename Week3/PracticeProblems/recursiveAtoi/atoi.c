#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//function declaration;
int convert(string input);

int main(void)
{
    //gets the user input;
    string input = get_string("Enter a positive integer: ");
    int n = strlen(input);

    //checks if every character inputed is a ASCII digit, if isnt, return an error
    //message and stops the program;
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    //Convert string to int;
    printf("%i\n", convert(input));

}

int convert(string input)
{
    //base case;
    if (input[0] == 0)
    {
        return 0;
    }

    //a variable that store the number characters of input;
    //a variable that store the correspondent integer number of a digit character (ASCII);
    //the final character of input is replaced by the null terminator (\0), wich is in n
    //position of input;
    int n = strlen(input);
    int number = input[n - 1] - 48;
    input[n - 1] = input[n];

    //recursive case;
    return number + (10 * convert(input));

}