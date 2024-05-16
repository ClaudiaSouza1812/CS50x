#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//to consider the wav librarie;
#include "wav.h"

//functions prototypes;
int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

//create a data type that has 1 Byte as space;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // TODO #1
    //checks if the argument has exactly 3 items;
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav factor\n");
        return 1;
    }

    // TODO #2
    // Open input file for reading;
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // TODO #3
    //declaration of a variable with WAVHEADER structure;
    WAVHEADER header;

    // Read header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    //variable to check the actual position of the input file pointer;
    long pi = ftell(input);

    // TODO #4
    // Use check_format to ensure WAV format;
    if (check_format(header) == 1)
    {
        printf("Not a Wave file\n");
        return 3;
    }

    // TODO #5
    // Open output file for writing;
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 4;
    }

    // TODO #6
    // Write header to file;
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    //variable to check the actual position of the output file pointer;
    long po = ftell(output);

    // TODO #7
    // Use get_block_size to calculate size of block;
    BYTE BLOCK_SIZE = get_block_size(header);

    //variable to set the offset for further use;
    long offset = BLOCK_SIZE * - 2;

    // TODO #8
    // Write reversed audio to file;

    //provisory buffer to store values;
    BYTE buffer[BLOCK_SIZE];

    //function call to set the input pointer to the last byte of the file opened;
    fseek(input, BLOCK_SIZE * - 1, SEEK_END);

    //variable to check the actual position of the input file pointer;
    pi = ftell(input);

    //loop that will read the file while it is returning a valid number of bytes;
    while (fread(buffer, BLOCK_SIZE, 1, input))
    {
        //variable to check the actual position of the input file pointer;
        pi = ftell(input);

        //a condition to check if the pointer position is greater than the header size,
        //if it is, will write the buffer value to the output file, to map the actual pointer position
        //and send it back 2 blocks;
        if (pi >= sizeof(header))
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
            po = ftell(output);
            fseek(input, offset, SEEK_CUR);
            pi = ftell(input);
        }
        //a condition that will close the files and end the programm if the pointer is in a position
        //less than size of header (44 bytes);
        if (pi < sizeof(header))
        {
            fclose(input);
            fclose(output);
            return 0;
        }
    }
}


int check_format(WAVHEADER header)
{
    // TODO #4
    //if the structure data selected was equal to the keyword, return 0 (true),
    //else, return 1 (false);
    char keyword[4] = {'W', 'A', 'V', 'E'};
    int n = 0;
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] == keyword[i])
        {
            n++;
        }
    }
    if (n == 4)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    //transforms bits in bytes by divide the data by 8, after that,
    //multiply numChannels times, giving the final block size;
    BYTE n = 0;
    n = header.numChannels * (header.bitsPerSample / 8);

    return n;
}