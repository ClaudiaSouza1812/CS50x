#include <stdio.h>
#include <cs50.h>
#include <string.h>

//function that checks is a condition is true
bool check_phrase(string phrase);

int main(void)
{
    //variable that prompt the user the password and store it
    string answer = get_string("Whats the secret phrase? \n");
    //variable that store the result of the check
    bool check = check_phrase(answer);

    if (check == true)
    {
        printf("Come in \n");
    }
    else
    {
        printf("Wrong answer \n");
    }
}

bool check_phrase(string phrase)
{
    //variable that store the password
    string password = "shazam";
    //function that compars two strings and return 0 if its true
    if (strcmp(phrase, password) == 0)
    {
        return true;
    }
    return false;
}