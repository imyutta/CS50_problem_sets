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
// while creating a copy of the memory card
// look for the beginning of a JPEG file
// and each time you find a signature
    //open a new jpeg file
    //fill this jpeg file with bytes from the memory card
    //till you meet another signature
    // read 512 at a time
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
    }


    char* jpeg_name = malloc(4 * sizeof(char));
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
    for (int i = 0; i < 50; i++)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(jpeg_name, "%03i.jpg", i);
            FILE* img = fopen(jpeg_name, "w");
            do
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }
            while (buffer[n] != 0xff)
        }
    }






    fclose(file);
    free(buffer);
    free(jpeg_name);
    return 0;
}
