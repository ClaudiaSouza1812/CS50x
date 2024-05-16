#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//this is a program to transform lower case letters in upper case letters;
int main(void)
{
    //prompt the user to type the word;
    string s = get_string("Before ");
    //print the word after;
    printf("After: ");
    //loop to check every single letter in the word typed by the user;
    //strlen counts how many letters the word typed has, wich will serve as parameter to the counter i;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    //go to the next line;
    printf("\n");
}