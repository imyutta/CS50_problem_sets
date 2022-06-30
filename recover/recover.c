#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

//copy of the file
    //allocate memory for the file
    typedef uint8_t BYTE;
    int BLOCK_SIZE = 512;
    BYTE* buffer = malloc(sizeof(BYTE));
    if (buffer == 0)
    {
        printf("Could not open the file");
        fclose(file);
        return 1;
    }
    // create a copy of the memory card
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
    }

//look for the beginning of a JPEG file
    //if (file[0] == 0xff && file[1] == 0xd8 && file[0] == 0xff)


// each time you find a signature
    //open a new file
    //fill this file with bytes from the memory card
    //till you meet another signature
    // read 512 at a time
    for (int i = 0; i < 50; i++)
    {
        FILE *000 =
    }





}
