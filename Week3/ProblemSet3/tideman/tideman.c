#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int loser, int actualwinner);

//main function that returns an integer, receive an integer and an array of strings by the terminal;
int main(int argc, string argv[])
{
    // Check for invalid usage, need to be at least 2 candidates;
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    //check if the name typed, lower or uppercase, is valid, consulting the candidates array.
    //if it is, the array ranks store the rank argument in the j position;
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcasecmp(name, candidates[j]) == 0)
        {
            ranks[rank] = j;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //this loop will populate the preferences two-dimencional array, where i is the candidate
    //that wins over the j candidate. It will receive the prefered candidate of rank as i, and
    //the second one as j, wich means it will go to the i row, on the j column and sum 1 point
    //to the value stored in its cell;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //aloop that will compare the candidate i over candidte j value with the candidate
    //j over candidate i, if one of them is bigger, the it will access the pairs array,
    //wich have two data types and fill them with the winner and loser number;
    int k = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
                k++;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[k].winner = j;
                pairs[k].loser = i;
                k++;
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int c = - 1;
    int a = pair_count;
    pair change[1];

    //a loop that will sort the pairs array using the bubble sort algorithm and another one
    //that will calculete the strength of victory, to do that, it will take the winner and loser value,
    //store in variables and use them as key to the preferences two-dimensional array, after that,
    //will subtract them and store the result in the strenghths variables. The conditional command if
    //will check if the first is smaller over the second, if its so, will switch them on the pairs array;
    for (int p = 0; c != 0; p++)//bubble sort;
    {
        a--;
        c = 0;

        for (int m = 0, r = m + 1; m < a; m++, r++)
        {
            int w1 = pairs[m].winner;
            int l1 = pairs[m].loser;
            int strength1 = preferences[w1][l1] - preferences[l1][w1];

            int w2 = pairs[r].winner;
            int l2 = pairs[r].loser;
            int strength2 = preferences[w2][l2] - preferences[l2][w2];

            if (strength1 < strength2)
            {
                change[0] = pairs[m];
                pairs[m] = pairs[r];
                pairs[r] = change[0];
                c++;
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    //a loop that will call the check_cycle function, if its return false, will "lock" the pairs
    //winner position on the loser column, switching the previous status false to true;
    for (int i = 0; i < pair_count; i++)
    {
        if (check_cycle(pairs[i].loser, pairs[i].winner) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

//a function that checks if the actual pair has the potencial to make a circle;
bool check_cycle(int loser, int actualwinner)
{
    //recursion base case;
    //if the two of them has the same number, will return true;
    if (loser == actualwinner)
    {
        return true;
    }

    //a loop that checks is the loser has true, wich means, if its points a arrow to
    //other candidate, if its so, the function will call itself again, with the i counter as loser,
    //and the winner as winner. If the previous loser points to the actual winner, will return true,
    //wich means that it can make a circle, so it wont be locked on the lock_pairs function, if the oposite
    //the cell will be locked;
    for (int i = 0; i < candidate_count; i++) //recursive case
    {
        if (locked[loser][i] == true)
        {
            if (check_cycle(i, actualwinner))
            {
                return true;
            }
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    int j = 0;
    //a loop that will check if every candidate column has a true in every row, wich means a locker,
    //if it has, it cant be the winner, so the loop will check the next candidate on the next column,
    //otherwise, will check the next line of the same candidate, if it hasnt a locker, this candidate will the winner;
    for (int i = 0; i < candidate_count; i++)
    {
        for (j = 0; j < pair_count; j++)
        {
            if (locked[j][i] == true)
            {
                break;
            }
            if (j == candidate_count - 1)
            {
                printf("%s", candidates[i]);
                printf("\n");
                break;
            }
        }
    }
    return;
}