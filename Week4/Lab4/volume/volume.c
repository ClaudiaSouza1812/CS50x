// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //converts the string inputed to a float number;
    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    //array with 44 positions of 1 byte;
    uint8_t header[HEADER_SIZE];

    //read from input to header, 1 time, 44 bytes;
    //write from header to output, 1 time, 44 bytes;
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer;
    //while fread is abble to read the file (wich means, returning true, because the file still have data)
    //read from input to buffer address, 1 time, 2 bytes (16 bits);
    //multiply the value stored in buffer by the factor;
    //write to output from buffer address, 1 time, 2 bytes (16 bits);
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}





