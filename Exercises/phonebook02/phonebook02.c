#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //fopen its a function thats open a file and return a pointer there to in memory,
    //it receives as arguments the file name and the way it will allow us to keep
    //adding more names and numbers to this file;
    FILE *file = fopen("phonebook.csv", "a");

    string name = get_string("Name: ");
    string number = get_string("Number: ");

    //print things not to the screen, but to a file, as arguments, you have to say to waht file
    //you want to print it, after that, the quote and data type you want to use as a source,
    //finally, the data types variables thet stores the values;
    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
}