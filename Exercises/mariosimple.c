#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    int n = get_size();
    print_grid(n);

}
//above are the functions created;


//int because it has an output, void because it dont have an input;
//this function request the user input, check if its is in the determined
//range, if so, return the value;
int get_size(void)
{
   //user input of the size of retangle
    int n;
    //user input control
    do
    {
        n = get_int("Rectangle height: ");
    }
    while (n < 1 || n > 4);
    return n;
}


//void because it dont have an output, int because it has an input;
//this function receive the user input as condition to run a loop,
//the value stabilish how many times the loop will work, first, making
//the line, second, printing the rashes, last, move to the next line;
void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int s = 0; s < size; s++)
        {
            // print a brick
            printf("#");
        }
        // move to the next row
        printf("\n");
    }
}

