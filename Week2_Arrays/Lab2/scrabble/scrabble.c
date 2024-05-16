#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //printf("%i %i \n", score1, score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

// TODO: Compute and return score for string
int compute_score(string word)
{
    int n = strlen(word);
    char value[n];

    for (int i = 0; i < n; i++)
    {
        value[i] = word[i];
        //printf("%c\n", value[i]);
    }

    for (int j = 0; j < n; j++)
    {
        if (islower(value[j]))
        {
            value[j] = value[j] - 32;
            //printf("%c\n", value[j]);
        }
    }

    char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //printf("%c\n", LETTERS[1]);
    //printf("%i\n", POINTS[1]);

    int sum = 0;
    int m = 0;

    for (int h = 0; h <= m; h++)
    {
        for (int k = 0, l = 26; k < l; k++)
        {
            if (LETTERS[k] == value[m])
            {
                sum = sum + POINTS[k];
                m++;
            }
        }
    }
    return sum;
}
