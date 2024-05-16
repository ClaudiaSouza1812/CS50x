#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //gets the voters number;
    int voter_count = get_int("Number of voters: ");

    // Loop that request users vote with candidate name specified;
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //loop that checks if the names entered are the same as those available in the array, if so,
    //it will add 1 vote to the candidate and return true, otherwise it will return false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int n = candidate_count;
    int w;

    //a loop that identifies the highest value in the array, starts by setting w to its first value,
    //changing it if a new higher value is found;
    for (int i = 0; i < 1; i++)
    {
        w = candidates[i].votes;
        for (int j = 1; j < n; j++)
        {
            if (candidates[j].votes > w)
            {
                w = candidates[j].votes;
            }
        }
    }

    //a loop that will print every candidate who has the higher value, identified by w;
    for (int k = 0; k < n; k++)
    {
        if (candidates[k].votes == w)
        {
            printf("%s", candidates[k].name);
            printf("\n");
        }
    }
    return;

}