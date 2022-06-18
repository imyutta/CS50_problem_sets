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

    float factor = atof(argv[3]);


    // create an array of n bytes for the header
    uint8_t header[HEADER_SIZE];
    // if (header == NULL)
    // {
    //     return 1;
    // }
    // if (strlen(header) > 0)
    // {
        // Copy header from input file to output file
        fread(header, HEADER_SIZE, 1, input);
        fwrite(header, HEADER_SIZE, 1, output);
        free(header);
    // }

    // TODO: Read samples from input file and write updated data to output file
    //read
    //update the volume
    //write

    int16_t buffer;
    // if (buffer == NULL)
    // {
    //     return 1;
    // }

    while(fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}
