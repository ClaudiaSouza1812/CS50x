#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a;

    printf("a has the value %i, located at %p\n", a, &a);
    printf("b has the value %i, located at %p\n", b, &b);
    printf("c has the value %p, located at %p\n", c, &c);
    printf("\n");

    *c = 14;
    c = &b;
    *c = 25;

    printf("a has the value %i, located at %p\n", a, &a);
    printf("b has the value %i, located at %p\n", b, &b);
    printf("c has the value %p, located at %p\n", c, &c);
}