#include <stdio.h>
//prototipe of swap, which receive the address of two integers;
void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    //swap function receive as arguments the information of the x and y address
    //in memory by the ampersend (&) signal, in short, &x and &y are informing theirs addresses;
    swap(&x, &y);

    printf("x is %i, y is %i\n", x, y);
}


//swap function receives the order to go, to point, by asterisk signal (*), to the address, in memory,
//informed before in the main function by the ampersend signal (&), in short, *a and *b are pointing
//to the values stored in the addresses;
void swap(int *a, int *b)
{
    //tmp receives the value stored in the address of a;
    //the address of a receives the value stored in the address of b;
    //finally, b receives the value stored in tmp;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}