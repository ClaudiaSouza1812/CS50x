#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int list[16] = {0, 11, 23, 8, 14, 30, 9, 6, 17, 22, 28, 25, 15, 7, 10, 19};
    int n = get_int("Type the number: ");
    int l = sizeof(list) / sizeof(list[0]);

    for (int i = 0; i < l; i++)
    {
        if (n == list[i])
        {
            printf("%i found\n", list[i]);
            return 0;
        }
    }
    printf("%i not found\n", n);
    return 1;

}
