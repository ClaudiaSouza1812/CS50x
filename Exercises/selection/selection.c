#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int list[] = {11, 23, 8, 14, 30, 9, 6, 17, 22, 28, 25, 15, 7, 10, 19};

    int n = sizeof(list) / sizeof(list[0]);
    int replace[1];
    //printf("%i \n", n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (list[i] <= list[j])
            {
                list[i] = list[i];
            }
            else
            {
                replace[0] = list[j];
                list[j] = list[i];
                list[i] = replace[0];
            }
        }
        printf("%i", list[i]);
    }
    printf("\n");





}