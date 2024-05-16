#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//create a data type that has 1 Byte as space;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checks if the argument has exactly two items;
    if (argc != 2)
    {
        printf("Input only one file name\n");
        return 1;
    }

    //create a file that points to the second argument in read mode;
    FILE *input = fopen(argv[argc - 1], "r");

    //checks if the file is pointing to a NULL place of memory;
    if (input == NULL)
    {
        printf("Could not open file.\n");
        fclose(input);
        return 1;
    }

    //create a integer with 512 bytes, a buffer with 512 positions of 1 byte and the output file
    //that will point to some place in memory;
    int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];
    FILE *output;

    //create a buffer to a file name, a counter and an index;
    char filename[17];
    int counter = 0;
    int i = 0;

    //while the function result is true, wich means, it is returning a value greater than 0,
    //keep reading the file;
    while (fread(buffer, BLOCK_SIZE, 1, input))
    {
        //checks if it is a JPG file by checking the "i" index of buffer looking for the JPG identifyers;
        if (buffer[i] == 0xff && buffer[i + 1] == 0xd8 && buffer[i + 2] == 0xff && (buffer[i + 3] & 0xf0) == 0xe0)
        {
            //checks if are a file alredy opened, if its so, will close it;
            if (counter != 0)
            {
                fclose(output);
            }

            //will create a new filename and iterate the counter;
            //the output file will point to the filename place in memory and open it in write mode;
            //the buffer data will be writed to the output file;
            sprintf(filename, "%03i.jpg", counter++);
            output = fopen(filename, "w");
            fwrite(&buffer, BLOCK_SIZE, 1, output);
        }

        //if isn't a JPG identifyer, and the counter is greater than 0, it means there's an JPG
        //alredy open and this data will be continuosly written in it
        else if (counter > 0)
        {
            fwrite(&buffer, BLOCK_SIZE, 1, output);
        }
    }
    fclose(input);
    fclose(output);
}