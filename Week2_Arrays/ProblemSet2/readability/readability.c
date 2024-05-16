#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//functions that receives a string argument and return an integer result;
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompts to user a text request;
    string text = get_string("Text: \n");
    //printf("%s\n", text);

    //a float variable that receives two integer functions, transform its values
    //in float results, calcutate its values and return a float result;
    float l = ((float)count_letters(text) / (float)count_words(text)) * 100;
    float s = ((float)count_sentences(text) / (float)count_words(text)) * 100;
    //an integer variable that calculates float values and round the result to
    //the nearest integer;
    int index = round((0.0588 * l) - (0.296 * s) - 15.8);

    //printf("%i letters\n", count_letters(text));
    //printf("%i words\n", count_words(text));
    //printf("%i sentences\n", count_sentences(text));

    //a condition that will print a text depending on the variable index result;
    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }



}

//functions that receives a string argument and return an integer result;
int count_letters(string text)
{
    //a integer variable that store the number of text letters;
    int n = strlen(text);
    //a character array variable with the same position as the number of word letters;
    char filter[n];
    //an integer variable that will store the number of letters from capital A to Z;
    int letters = 0;

    //a loop that will scroll through all positions filter array allocating each value
    //of text array in it, also will change all letters to upper case;
    for (int i = 0; i < n; i++)
    {
        filter[i] = text[i];
        filter[i] = toupper(filter[i]);
    }

    //a loop that will count how many letters between A an Z there are and store it in letters;
    for (int j = 0; j < n; j++)
    {
        if (filter[j] > 64 && filter[j] < 91)
        {
            letters++;
        }
    }
    return letters;
}

//functions that receives a string argument and return an integer result;
int count_words(string text)
{
    //a integer variable that store the number of text letters;
    int n = strlen(text);
    //an integer variable that store the text number of words, assuming that the sentence
    //initiates with one word;
    int words = 1;

    //a loop that will scroll through all positions of text array searching the spaces
    //between words, each time it find one means that a new word starts past it;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words;
}

//functions that receives a string argument and return an integer result;
int count_sentences(string text)
{
    //a integer variable that store the number of text letters;
    int n = strlen(text);
    //an integer variable that store the text number of sentences;
    int sent = 0;

    //a loop that will scroll through all positions of text array searching the dots,
    //question and exclamation characters between words, each time it find one means that
    //theres a sentence before it;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sent++;
        }
    }
    return sent;
}