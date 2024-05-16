#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//function with boolean return and a string as argument;
bool only_digits(string dig);
//a function that return a integer, that will receive the arguments by terminal and check these with
//the two arguments, argc will count the number of arguments typed by user, argv[] will store the chosen
//argument in an array;
int main(int argc, string argv[])
{
    //a condition that cheks if the arguments typed on terminal are different of 2, if it is,
    //the program will stop because it has to be 2;
    if (argc != 2)
    {
        //prompt user to type a key;
        printf("Usage: ./caesar key\n");
        //the return 1 stops the program, wich means that the following commands will not start;
        return 1;
    }

    if (only_digits(argv[1]) != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //a variable thats store the second argument typed on terminal (position 1 of the array) and
    //turn it from a string to an integer;
    int key = atoi(argv[1]);
    printf("%i\n", key);
    //prompt the user the plaintext and store it in the plain variable;
    //a integer variable thats store the number characters of plain;
    //an array with n positions;
    //an array with the alphabet stored;
    string plain = get_string("plaintext: \n");
    int n = strlen(plain);
    int cipher[n];
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    printf("ciphertext: ");
    //a loop that will pass through the conditions until reaches n times;
    for (int i = 0; i < n; i++)
    {
        //a condition thats checks if every letter is lower, if it is, will store in cipher array,
        //them will make a math to change the ASCII number of it into an alphabetic index, in wich
        // 0 is A, 1 is B and so forth. After that we need to use the formula Ci = (Pi + k) % 26 wich
        //the result is the modulo 26 reminder that will determine the number of the new word in the index,
        //after that, we need to use the cipher value as argument inside the alpha array to select the
        //respective letter, finally we will print it in lower case;
        if (islower(plain[i]))
        {
            cipher[i] = plain[i];
            cipher[i] = cipher[i] - 97;
            cipher[i] = (cipher[i] + key) % 26;
            cipher[i] = alpha[cipher[i]];
            printf("%c", tolower(cipher[i]));
        }
        //same steps above, after we will print it in upper case;
        else if (isupper(plain[i]))
        {
            cipher[i] = plain[i];
            cipher[i] = cipher[i] - 65;
            cipher[i] = (cipher[i] + key) % 26;
            cipher[i] = alpha[cipher[i]];
            printf("%c", cipher[i]);
        }
        //will print all non alphabetical characters;
        else
        {
            printf("%c", plain[i]);
        }
    }

    printf("\n");
    //will stop the program;
    return 0;
}

//function with boolean return and a string as argument;
bool only_digits(string dig)
{
    //a integer variable thats store the number characters of dig;
    int n = strlen(dig);
    bool status = false;
    //a loop that will check if the value typed by the user is a decimal number, if it is, will return true,
    //if its not, will return false and the ptogram will stops;
    for (int i = 0; i < n; i++)
    {
        if (dig[i] >= 48 && dig[i] <= 57)
        {
            status = true;
        }
        else
        {
            status = false;
            break;
        }
    }
    return status;
}