#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 18277;

node *table[N];

int n_size = 0;

void free_malloc(node *n);

bool check(const char *word)
{
    int index = hash(word);
    node *ptr = table[index];

    if (ptr != NULL)
    {
        while (ptr->next != NULL)
        {
            if (strcasecmp(word, ptr->word) == 0)
            {
                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}

unsigned int hash(const char *word)
{
    if (word[1] != '\0' && word[2] != '\0')
    {
        return (((((toupper(word[0]) - 'A') + 1) * 26) * 26) + (toupper(word[1]) - 'A' + 1) * 26) + toupper(word[2]) - 'A';
    }
    if (word[1] != '\0')
    {
        return (((toupper(word[0]) - 'A') + 1) * 26) + toupper(word[1]) - 'A';
    }
    else
    {
        return toupper(word[0]) - 'A';
    }
}

bool load(const char *dictionary)
{
    FILE *infile = fopen(dictionary, "r");

    if (infile == NULL)
    {
        printf("Error opening file!\n");
        return false;
    }
    char buffer[LENGTH + 1];

    while (fscanf(infile, "%s", buffer) != EOF)
    {
        int index = hash(buffer);
        n_size++;

        if (table[index] == NULL)
        {
            table[index] = malloc(sizeof(node));

            if (table[index] == NULL)
            {
                printf("Can't allocate memory for it.\n");
                return false;
            }
            table[index]->next = NULL;

            node *ptr = malloc(sizeof(node));

            if (ptr == NULL)
            {
                printf("Can't allocate memory for it.\n");
                return false;
            }
            strcpy(ptr->word, buffer);
            ptr->next = table[index];

            table[index] = ptr;
        }
        else if (table[index] != NULL)
        {
            node *ptr = malloc(sizeof(node));

            if (ptr == NULL)
            {
                printf("Can't allocate memory for it.\n");
                return false;
            }
            strcpy(ptr->word, buffer);
            ptr->next = table[index];

            table[index] = ptr;
        }
    }
    fclose(infile);
    return true;
}

unsigned int size(void)
{
    if (n_size > 0)
    {
        return n_size;
    }
    return 0;
}

bool unload(void)
{
    int index = 0;
    while (index != N)
    {
        if (table[index] != NULL)
        {
            node *ptr = table[index];

            free_malloc(ptr);
            index++;
        }
        else
        {
            index++;
        }
    }
    if (index == N)
    {
        return true;
    }
    return false;
}

void free_malloc(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    free_malloc(ptr->next);
    free(ptr);
}