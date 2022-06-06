#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string k);

int main(int argc, string argv[])
{
    //check if there is only one command-line argument
    if (argc != 2)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }

    //check whether argv[1] is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //make int argv[1]
    int k = atoi(argv[1]);

    //ask user for text
    string text = get_string("plaintext: ");

    // for each character in the user's text:

    //rotate each letter(but only if it is a letter)




}

//a function checks if argv[] contains only digits
bool only_digits(string k)
{
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isdigit(k[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate (char character, int key)
{
    if (int character >= 65 && int character <= 90)
    {
        int character += key;
    }


}