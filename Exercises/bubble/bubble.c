#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int length(int list[]);

int main(void)
{
    int numbers[] = {11, 23, 8, 14, 30, 9, 6, 17, 22, 28, 25, 15, 7, 10, 19};
    int n = length(numbers);
    int r = 1;
    int c = -1;
    int replace[r];
    int a = n;

    for (int i = 0; c != 0; i++)
    {
        a--;
        c = 0;
        for (int l = 0, j = l + 1; l < a; l++)
        {
            if (numbers[l] > numbers[j])
            {
                replace[r] = numbers[j];
                numbers[j] = numbers[l];
                numbers[l] = replace[r];
                c++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }

    for (int m = 0; m < n; m++)
    {
        printf("%i", numbers[m]);
    }
    printf("\n");
}


int length(int list[])
{
    int n = 0;
    for (int i = 0; list[i] != 0; i++)
    {
        n++;
    }
    return n;
}