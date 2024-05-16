#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    float a = get_float("type the first side of the triangle: \n");
    float b = get_float("type the second side of the triangle: \n");
    float c = get_float("type the third side of the triangle: \n");
    float d = valid_triangle(a, b, c);
    printf("result: %f\n", d);
}

bool valid_triangle(float x, float y, float z)
{
    //check for all positive sides
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }
    //check that sum of any two sides greater than third
    if (( x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }
    //if we passed both tests, we're good
    return true;
}