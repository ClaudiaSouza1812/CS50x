//request to the program to include these libraries;
#include <stdio.h>
#include <cs50.h>
#include <math.h>

//a function thats return a float value and receives two integer arguments,
//one of them being an array;
float average(int length, int array[]);
//a function that has a return but dosen't receives an argument;
int main(void)
{
    //declaration of a variable with 0 as a value, it will receive
    //from the user, further ahead, the score value;
    int n = 0;
    //a loop thats request the user how many scores it will have, limited
    //by 2 to 10, it will be the parameter to build the array that will store them;
    do
    {
        n = get_int("How many scores? \n");
    }
    while (n < 2 || n > 10);
    //declaration of an array variable thats will have the range informed
    //by the user (n);
    int scores[n];
    //a loop that will store the values of each one of the array positions,
    //using as a range the value inputted by the user (n);
    for (int i = 0; i < n; i++)
    {
        //request to user each one of the score values;
        scores[i] = get_int("Score: ");
    }
    //a function thats print the result using as argument the average function
    //with "n" and "scores" as its arguments;
    printf("Average: %.4f\n", average(n, scores));
}

//a function thats return a float value and receives two integer arguments,
//one of them being an array;
float average(int length, int array[])
{
    //a variable that will be used to storage the sum of the array values,
    //defined before;
    int sum = 0;
    //a loop that will go through the values stored in the array and
    //will sum it, the result will be the new value of the variable sum;
    for (int i = 0; i < length; i++)
    {
        sum = sum + array[i];
    }
    //returns the variable "sum" value divided by the length (n) in float format
    //(decimal number);
    return sum / (float) length;
}