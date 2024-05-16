// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

//definition of a range to be used inside an array;
#define NUM_CITIES 10

//declaration of a struct definition that has 2 data types, one string and other integer,
//its name will be avg_temp, wich will be used to declare a variable that will have these
//data types declared in this structure;
typedef struct
{
    string city;
    int temp;
}
avg_temp;

//declaration of a variable called temps that will have 10 positions, as defined in NUM_CITIES above;
avg_temp temps[NUM_CITIES];
//declaration of a variable called store that will have only 1 position, because it will be a transition structure
//only to swap the datas in the temps structure;
avg_temp store[1];

//a function with no return that takes a structure of data as argument;
void sort_cities(avg_temp list[]);

int main(void)
{
    //the alocation of data in every array position;
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    //a function call to treat the temps data;
    sort_cities(temps);

    //print a text before the cities;
    printf("\nAverage July Temperatures by City\n\n");

    //will print every of each city temperature;
    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

//Sort cities by temperature in descending order
void sort_cities(avg_temp list[])
{
    //n is the the counter variable to be used in the bubble sort algorithm;
    //t is the counter to subtract the range of the array;
    int n = -1;
    int t = NUM_CITIES;

    //a loop that repeat itself until the counter n is equal to zero;
    for (int i = 0; n != 0; i++)
    {
        //reset n to zero;
        //decrease the t range (check limit of the array);
        n = 0;
        t--;

        //a loop that will check the lowest degrees, swap and push them to the last positions
        //of the array, that way, printing the array in descending order;
        for (int j = 0; j < t; j++)
        {
            if (list[j].temp < list[j + 1].temp)
            {
                store[0] = list[j];
                list[j] = list[j + 1];
                list[j + 1] = store[0];
                n++;
            }
        }
    }
}
