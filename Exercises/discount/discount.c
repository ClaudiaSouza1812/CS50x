#include <cs50.h> //telling the compiler to load cs50 library;
#include <stdio.h> //telling the compiler to load standard input and output library, in wich we have the integer, string e etc data type;

//declaration of discount function
//the variable regular ask the user the regular price
//the variable percent_off ask the user the percentual of discount
//the variable sale call the function discount, wich will receive the value of the
//variables regular and percent_off as imput
//the discount function will make the math and return the value
//the printf will print the text and the result

float discount(float price, int percentage);

int main(void)
{
    float regular = get_float("Regular price: ");
    int percent_off = get_int("Percent Off: ");
    float sale = discount(regular, percent_off);
    printf("Sale Price: %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price * (100 - percentage) / 100;
}