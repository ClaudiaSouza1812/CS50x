#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates[3];
    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate("Enter a candidate: ");
    }

    printf("%s\n", candidates[0].name);
    printf("%i\n", candidates[0].votes);
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter a number of votes: ");
    return c;

}