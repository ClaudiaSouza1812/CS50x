// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

//a function that return a boolean expression and has a string as argument;
bool valid(string password);
//a function that returns an integer, bus dosen't has an argument as input;
int main(void)
{
    //a variable that prompt the user his password and store it;
    string password = get_string("Enter your password: ");
    //a condition that uses a funciton called valid to check the password stored in the variable
    //its true and prints its analisys;
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
//a function that return a boolean expression and has a string as argument;
bool valid(string password)
{
    // variable that will count, by the funcion strlen, the number of characters
    //from password word and store it;
    int n = strlen(password);
    //a chart array variable with the munbers of position provided by strlen of password;
    char word[n];
    //a loop that will store each character of password in the array chart
    //variable;
    for (int i = 0; i < n; i++)
    {
        word[i] = password[i];
        //printf("%c\n", word[i]);
    }
    //boolean variables that will store the result of the loop;
    bool number = false;
    bool symbol = false;
    bool upper = false;
    bool lower = false;
    //a loop that will check every character of word to find if its satisfact the conditions;
    for (int j = 0; j < n; j++)
    {
        //checks if password has numbers;
        if (word[j] >= 48 && word[j] <= 57)
        {
            number = true;
        }
        //checks if password has symbols;
        if (word[j] >= 33 && word[j] <= 47)
        {
            symbol = true;
        }
        //checks if password has upper letters;
        if (word[j] >= 65 && word[j] <= 90)
        {
            upper = true;
        }
        //checks if password has lower letters;
        if (word[j] >= 97 && word[j] <= 122)
        {
            lower = true;
        }
    }
    //a boolean variable seted as false;
    bool comparison = false;
    //a loop that checks if all the conditions of the previusly loop are true, if its so,
    //its value will change from false to true;
    if (number == true && symbol == true && upper == true && lower == true)
    {
        comparison = true;
    }

    return comparison;
}
