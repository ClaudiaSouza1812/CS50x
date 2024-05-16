#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    //open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    //check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    //uint8_t meas: unsigned integer (only positive integers) of 8 bits (1 byte) all together;
    uint8_t buffer[4];
    uint8_t signature[] = {37, 80, 68, 70};

    fread(buffer, 1, 4, file);

    //does the buffer signature match?
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a PDF");
            fclose(file);
            return 0;
        }
    }
    printf("Likely a PDF!\n");
    fclose(file);
    return 0;


}