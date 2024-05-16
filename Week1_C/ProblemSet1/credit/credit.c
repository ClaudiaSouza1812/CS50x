#include <cs50.h>
#include <stdio.h>
#include <math.h>


int calc_checksum(long n, int lenght);
int check_length(long n);
int check_card(long n, int lenght);



int main(void)
{
    // prompt to user the card number
    // check the card numbers length
    // run function Luhns algorithm
    // print the card number

    long n = get_long("Card number: ");
    int length = check_length(n);
    int check = calc_checksum(n, length);
    int card = check_card(n, length);
    //printf("%li\n", n);

    if (check == 0)
    {
        if (length == 13 || length == 16)
        {
            if (card > 39 & card < 50)
            {
                printf("VISA\n");
            }
            else if (card > 50 & card < 56)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 15)
        {
            if (card == 34 || card == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}



int check_length(long n)
{
    // numbers counter
    int count = 0;
    do
    {
        count++;
        n /= 10;
    }
    while (n != 0);
    //printf("%i\n", count);
    return count;
}

int check_card(long n, int length)
{
    int nc = 2;
    int c;
    int l = length;
    for (c = l; c > nc; c--)
    {
        n /= 10;
    }
    //printf("%li\n", n);
    return n;
}


int calc_checksum(long n, int length)
{
    int t = (length / 2) + 1;
    //printf("%i\n", t);
    int su = 0;
    int sp = 0;
    int mult = 2;

    for (int j = 0; j < t; j++)
    {
        int u = n % 10;
        n /= 10;
        su = su + u;
        //printf("%i\n", u);

        int p = n % 10;
        n /= 10;
        p = p * mult;
        if (p > 9)
        {
            int d2 = p % 10;
            p /= 10;
            int d1 = p % 10;
            p = d1 + d2;
        }
        sp = sp + p;
        //printf("%i\n", p);
    }
    //printf("Sum last %i\n", su);
    //printf("Sum sec last %i\n", sp);
    int total = sp + su;
    int lastnumber = total % 10;
    //printf("Last number %i\n", lastnumber);
    return lastnumber;
}




