// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
//a function that will return and take a string, beeing the argument an array;
string replace(string word[]);
//a function that will return an integer, and take an integer and a string array as argument;
int main(int argc, string argv[])
{
     //a variable thet will count the numbers of letters in the argv array;
     //int n = strlen(argv[1]);

     //a loop that will transform every letter in argv array in lower case;
     //for (int i = 0; i < n; i++)
     //{
          //if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
          //{
               //argv[1][i] = argv[1][i] + 32;
          //}
          //else
          //{
               //argv[1][i] = argv[1][i];
          //}
     //}
     //a function that will print the lower case word;
     //printf("%s\n", argv[1]);

     //a function that will check if 2 words was typed in the terminal, if it is so, will
     //will print the modified work in the replace function;
     if (argc != 2)
     {
          printf("Missing command-line argument\n");
          return 1;
     }
     else
     {
          printf("hello, %s\n", replace(argv));
          return 0;
     }
}

//a function that will return and take a string, beeing the argument an array;
string replace(string word[])
{
     //a loop that will, first, count the number of letters that the array has,
     //after, run itself until this number is reached;
     for (int i = 0, n = strlen(word[1]); i < n; i++)
     {
          //a condition that will check if each letter os the array has the following letter,
          //if it is so, will change them by the described numbers;
          if (word[1][i] == 'a' || word[1][i] == 'A')
          {
               word[1][i] = '6';
          }
          if (word[1][i] == 'e' || word[1][i] == 'E')
          {
               word[1][i] = '3';
          }
          if (word[1][i] == 'i' || word[1][i] == 'I')
          {
               word[1][i] = '1';
          }
          if (word[1][i] == 'o' || word[1][i] == 'O')
          {
               word[1][i] = '0';
          }
          else
          {
               word[1][i] = word[1][i];
          }
     }
     //will return the letters contained in the array;
     return word[1];
}








