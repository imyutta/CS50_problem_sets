#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
//check if the key is valid
    //check if argc = 2
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }
    //check if there are 26 letters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //check if the key contains only letters
    else if
    {
        printf("Key must contain alphabetic characters.\n");
        return 1;
    }


}

bool isKeyAlpha