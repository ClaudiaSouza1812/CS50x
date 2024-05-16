#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//a function thats return a float number and receives as argument two integers, beeing one of them
//an array, and one chart;
float calc_hours(int hours[], int weeks, char output);
//a function that returns a integer, but dosen't gave an argument as input;
int main(void)
{
    //prompt to user the number of weeks;
    int weeks = get_int("Number of weeks taking CS50: ");
    //create a integer array variable, its numbers of positions are defined by the number of weeks;
    int hours[weeks];
    //a loop that will prompt to the user the respective hours in each week and store them in
    //each position of the array;
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }
    //a loop that will prompt the user if he wants the total or average amount of week hours;
    char output;
    do
    {
        //a variable with a function that transform the letter typed in upper case, after, prompts
        //to the user the option chosed;
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    //will reapeat the loop whille the letter typed was different of T and A;
    while (output != 'T' && output != 'A');
    //print a float result with one decimal point as a result of calling the function;
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

//a function thats return a float number and receives as argument two integers, beeing one of them
//an array, and one chart;
float calc_hours(int hours[], int weeks, char output)
{
    //a variable thet will receive the sum of the hours;
    int sum = 0;
    //a loop that will sum the hours stored in the array;
    for (int i = 0; i < weeks; i++)
    {
        sum = sum + hours[i];
    }
    //a condition that will return the sum of hours if the letter T is typed;
    if (output == 'T')
    {
        return sum;
    }
    //a condition that will return the average of hours if the letter A is typed;
    else
    {
        return sum / (float) weeks;
    }
}