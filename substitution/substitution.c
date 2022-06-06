#include <cs50.h>
#include <stdio.h>
#include <string.h>


bool isKeyAlpha(string key);
bool isKeyUnrepeated(string key);

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
    else if (isKeyAlpha(key) == false)
    {
        printf("Key must contain alphabetic characters.\n");
        return 1;
    }
    else if (isKeyUnrepeated(key) == false)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    else
    {
        printf("GOOD\n");
    }
    return 0;



}

bool isKeyAlpha(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isalpha(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool isKeyUnrepeated(string key)
{
    int jShift = 1;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = jShift; j < (n - jShift); j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
        jShift += 1;
    }
    return true;
}