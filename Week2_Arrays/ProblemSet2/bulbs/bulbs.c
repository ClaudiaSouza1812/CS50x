#include <cs50.h>
#include <stdio.h>
#include <string.h>
//a constant integer thats atribute the number of bits to one byte;
const int BITS_IN_BYTE = 8;
//a function thats takes the binary number and turn it into emojis;
int print_bulb(int bit);

int main(void)
{
    //prompts the user for a message;
    //integer variable thats storage the messagem number of characters;
    string text = get_string("Message: ");
    int n = strlen(text);
    //declaration of an integer array with positions estabilished by BITS_IN_BYTE value;
    int bit[BITS_IN_BYTE];
    //a loop that will go through every character of text, check if its correspondent ASCII
    //chart decimal has a rest, if its so, will fill the bit array with zeros ans ones, wich
    //means the binary code of each one of them;
    for (int k = 0; k < n; k++)
    {
        for (int l = 7; l >= 0; l--)
        {
            if (text[k] % 2)
            {
                bit[l] = 1;
            }
            else
            {
                bit[l] = 0;
            }

            text[k] = text[k] / 2;
        }
        //a loop that will pass every binary number of the bit array through the print_bulb
        //function, wich will change the zeros to a black ball and the ones to a yellow ball,
        //printing them after that;
        for (int m = 0; m <= 7; m++)
        {
            print_bulb(bit[m]);
        }
        printf("\n");
    }
}

//a function thats takes the binary number and turn it into emojis;
int print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }

    return bit;
}
