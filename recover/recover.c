#include <stdio.h>
#include <stdlib.h>

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



    // create a copy of the memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open the file");
        return 1;
    }

//look for the beginning of a JPEG file


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
