#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command- Line argument\n");
        //any number different of 0 means to computer "false";
        return 1;
    }
        printf("hello, %s\n", argv[1]);
        //number 0 means to computer "true";
        return 0;

}