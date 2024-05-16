#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//a function that return a integer, that will receive the arguments by terminal and check these with
//the two arguments, argc will count the number of arguments typed by user, argv[] will store the chosen
//argument in an array;
int main(int argc, string argv[])
{
    //an array with the alphabet stored;
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //a condition that cheks if the arguments typed on terminal are different of 2, if it is,
    //the program will stop because it has to be 2;
    if (argc != 2)
    {
        //prompt user to type a key;
        printf("Usage: ./substitution key\n");
        //the return 1 stops the program, wich means that the following commands will not start;
        return 1;
    }
    //a condition that cheks if the argument hasent 26 characters, if its so, the program will stop;
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //an array that will store the key typed as string in the terminal, as a char ;
    char key[26];
    //a loop that will store the value of argv in the key array;
    for (int i = 0; i < 26; i++)
    {
        key[i] = argv[1][i];
    }
    //a loop that will check if the characters are alphabetical, if its so, will change them
    //to uppercase;
    for (int j = 0; j < 26; j++)
    {
        if (isalpha(key[j]))
        {

            key[j] = toupper(key[j]);
        }
        else
        {
            printf("Key must contain only alphabetical.\n");
            return 1;
        }
    }
    //a loop that will check if the characters are repeted, because they can be typed only once,
    //if its so, will print the warning;
    for (int l = 25; l >= 0; l--)
    {
        for (int m = 0; m < l; m++)
        {
            if (key[m] == key[l])
            {
                printf("Key must have a character only once.\n");
                return 1;
            }
        }
    }
    //a variable that will store the plaintext promped to the user;
    //a variable that will store the characters number of plain;
    //an array with n positions that will store the ciphered message;
    string plain = get_string("plaintext: ");
    int n = strlen(plain);
    char cipher[n];

    printf("ciphertext: ");
    //a loop that will check the case letters, will change them depending on the case, after that;
    //will compair the characters of plain and the letters array, if its is equal, will store in cipher array
    //the correspondent key and print it;
    for (int p = 0; p < n; p++)
    {
        if (islower(plain[p]))
        {
            plain[p] = toupper(plain[p]);
            for (int r = 25; r >= 0; r--)
            {
                if (plain[p] == letters[r])
                {
                    cipher[p] = key[r];
                    cipher[p] = tolower(cipher[p]);
                    printf("%c", cipher[p]);
                    break;
                }
            }
        }
        else if (isupper(plain[p]))
        {
            for (int r = 25; r >= 0; r--)
            {
                if (plain[p] == letters[r])
                {
                    cipher[p] = key[r];
                    cipher[p] = toupper(cipher[p]);
                    printf("%c", cipher[p]);
                    break;
                }
            }
        }
        else
        {
            printf("%c", plain[p]);
        }
    }
    printf("\n");
    return 0;
}