#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;


int hash(string phrase);
void visualize(node *table[], int index);
void free_malloc(node *n);

int main(void)
{
    node *table[26];

    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: \n");
        int index = hash(phrase);
        printf("%s hashes to %i\n", phrase, index);

        if (table[index] == NULL)
        {
            table[index] = malloc(sizeof(node));

            if (table[index] == NULL)
            {
                printf("Can't allocate memory for it.\n");
                return 1;
            }
            
            table[index]->next = NULL;
        }

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Can't allocate memory for it.\n");
            return 1;
        }

        n->phrase = phrase;
        n->next = table[index];

        table[index] = n;

        visualize(table, index);

        if (i == 2)
        {
            free_malloc(n);
        }
    }
}

//return an index, 0 to 25 for a given word;
int hash(string phrase)
{
    return toupper(phrase[0]) - 'A';
}


void visualize(node *table[], int index)
{
    node *buffer[1];
    buffer[0] = table[index];
    printf("\n+-- List Visualizer ----+\n\n");
    while (buffer[0]->next != NULL)
    {
        printf("Location: %p\n", buffer[0]);
        printf("Phrase: %s\n", buffer[0]->phrase);
        printf("Next: %p\n\n", buffer[0]->next);
        buffer[0] = buffer[0]->next;
    }
        printf("+-----------------------+\n\n");

}

void free_malloc(node *n)
{
    if (n == NULL)
    {
        return;
    }

    free_malloc(n->next);

    free(n);
}