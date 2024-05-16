#include <stdio.h>
#include <cs50.h>
#include <math.h>

//this is a recursive function, it mean that it call itself many times as needed to
//acomplish a task, in this case, will do the collatz calculation, wich divide a number
//by 2 if it is even or multiply 3 * n + 1 if it is odd ultil the final result is 1;
int collatz(int n);

int main(void)
{
    int n = get_int("Number: ");
    printf("%i \n", collatz(n));


}

int collatz(int n)
{
    //base case;
    if (n == 1)
    {
        return 0;
    }
    //recursive case one, if the number is even, wich tests if the number n módulo of 2 theres remainder,
    //if its not, will divide n by 2 until it reaches the number 1;
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n/2);
    }
    //recursive case two, if the number is odd, will multiply 3 by n plus 1, until it reaches the number 1;
    else
    {
        return 1 + collatz(3 * n + 1);
    }
}

