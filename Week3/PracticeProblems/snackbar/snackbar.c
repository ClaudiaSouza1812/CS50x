// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10

// Menu items have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];
// Add items to menu
void add_items(menu_item list[]);
// Calculate total cost
float get_cost(string item);

int main(void)
{
    //function thats add items to the menu;
    add_items(menu);

    //skip one line, print out the message and skip one line again;
    //print out the message and skip two lines;
    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    //print out every item of the menu;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }

    //skip one line;
    printf("\n");

    //declaration of a variable that will store the total cost of the items choosed;
    float total = 0;

    //a loop that will request to costumer the items wished until nothing is type;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        //return the total value plus the actual item cost;
        total += get_cost(item);
    }

    //print out the total value with two decimal places;
    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first four items to the menu array
void add_items(menu_item list[])
{
    //add the items to each place of menu array;
    list[0].item = "Burger";
    list[0].price = 9.5;
    list[1].item = "Vegan Burger";
    list[1].price = 11;
    list[2].item = "Hot Dog";
    list[2].price = 5;
    list[3].item = "Cheese Dog";
    list[3].price = 7;
    list[4].item = "Fries";
    list[4].price = 5;
    list[5].item = "Cheese Fries";
    list[5].price = 6;
    list[6].item = "Cold Pressed Juice";
    list[6].price = 7;
    list[7].item = "Cold Brew";
    list[7].price = 3;
    list[8].item = "Water";
    list[8].price = 2;
    list[9].item = "Soda";
    list[9].price = 2;

    return;
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    int n = NUM_ITEMS;
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        //a condition thats ignore the cases of the two variables and, if they are the same
        //returns the price of the item;
        if (strcasecmp(item, menu[i].item) == 0)
        {
            sum = sum + menu[i].price;
            break;
        }
    }

    if (sum == 0)
    {
        printf("Check the menu and type a valide item!\n");
    }

    //return the sum of the prices;
    return sum;
}
