#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "carter";
    people[0].number = "+1-617-495-1000";
    people[1].name = "david";
    people[1].number = "+1-949-468-2750";

    string name = get_string("Name: ");
    int n = strlen(name);

    for (int j = 0; j <= n; j++)
    {
        if (name[j] != islower(name[j]))
        {
            name[j] = tolower(name[j]);
        }

    }

    for (int i = 0; i <= 1; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("%s: %s\n", people[i].name, people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}