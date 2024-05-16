#include <stdio.h>
#include <cs50.h>
#include <math.h>


int merge(int array[], int n);
int sort(int left[], int right[], int array[], int n);

int main(void)
{
    int list[] = {3, 7, 8, 5, 4, 2, 6, 1};
    int n = sizeof(list) / sizeof(list[0]);

    merge(list, n);

    for (int i = 0; i < n; i++)
    {
        printf("%i\n", list[i]);
    }
}


int merge(int array[], int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int left[n / 2];
    int right[n / 2];

    for (int i = 0, j = n / 2; i < n / 2; i++, j++)
    {
        left[i] = array[i];
        right[i] = array[j];
    }

    n = n / 2;

    return merge(left, n) + merge(right, n) + sort(left, right, array, n);

}

int sort(int left[], int right[], int array[], int n)
{
    int i = 0, r = 0, l = 0;

    while (l < n && r < n)
    {
        if (left[l] < right[r])
        {
            array[i] = left[l];
            i++;
            l++;
        }
        else
        {
            array[i] = right[r];
            i++;
            r++;
        }
    }
    while (l < n)
    {
        array[i] = left[l];
        i++;
        l++;
    }
    while (r < n)
    {
        array[i] = right[r];
        i++;
        r++;
    }


    return 0;
}