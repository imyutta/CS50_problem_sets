#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>


int main(int argc, char *argv[])
{

//command-line argument is the name of the forensic image
//from which to recover JPEGs
    //check that there is only 1 command-line argument
    if (argc != 2)
    {
        printf("there must be only one argument");
        return 1;
    }

    //open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open the file");
        return 1;
    }


    //allocate memory for the file
    typedef uint8_t BYTE;
    int BLOCK_SIZE = 512;
    BYTE* buffer = malloc(sizeof(BYTE) * BLOCK_SIZE);
    if (buffer == 0)
    {
        printf("Could not crete a buffer to copy the file");
        fclose(file);
        return 1;
    }

//create jpeg-file name
    char* jpeg_name = malloc(4 * sizeof(char));
    int jpeg_number = 0;
    bool is_jpeg_open = 0;
    if (jpeg_name == NULL)
    {
        fclose(file);
        free(buffer);
        return 1;
    }
    if (sizeof(jpeg_name <= 0))
    {
        fclose(file);
        free(buffer);
        free(jpeg_name);
        return 1;
    }

// while creating a copy of the memory card
    // read 512 at a time
    // look for the beginning of a JPEG file
    // and each time you find a signature
        //open a new jpeg file
        //fill this jpeg file with bytes from the memory card
        //close when you meet another signature
    FILE* img = ma
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (is_jpeg_open == 0)
            {
                sprintf(jpeg_name, "%03i.jpg", jpeg_number);
                FILE* img = fopen(jpeg_name, "w");
                is_jpeg_open = 1;
                fwrite(buffer, 1, BLOCK_SIZE, img);
                jpeg_number += 1;
            }
            else if (is_jpeg_open == 1)
            {
                fclose(img);
                sprintf(jpeg_name, "%03i.jpg", jpeg_number);
                FILE* img = fopen(jpeg_name, "w");
                fwrite(buffer, 1, BLOCK_SIZE, img);
                jpeg_number += 1;
            }
        }
        else if (is_jpeg_open == 1)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }


    }


    fclose(file);
    fclose(img);
    free(buffer);
    free(jpeg_name);
    return 0;
}
