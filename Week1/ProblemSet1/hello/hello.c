#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;
#include <string.h>

//its a function thats has a return, but dont receives any argument
int main(void)
// the \n command put the $ on the next line;
// the %s command tells to the program to put a string here,
// that will be the string variable declared after it (answer);

{
    //prompts to the users to input theyr name
    string name = get_string("What is your name?\n");
    //prints "hello" plus the user input
    printf("hello, %s\n", name);
}