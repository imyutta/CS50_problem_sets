#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string k);
char rotate(char character, int key);


int main(int argc, string argv[])
{
    //check if there is only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check whether argv[1] is a non-negative digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //make int argv[1]
    int k = atoi(argv[1]);

    //ask user for text
    string text = get_string("plaintext: ");
    string textNew = text;

    // for each character in the user's text
    //rotate each letter(but only if it is a letter)
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        textNew[i] = rotate(text[i], k);
    }
    printf("ciphertext: %s\n", textNew);

    return 0;

}

//a function checks if argv[] contains only digits
bool only_digits(string k)
{
    if (atoi(k) < 0)
    {
        return false;
    }

    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isdigit(k[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

//a function convers a char letter with a key
char rotate(char character, int key)
{
    int characterASCII = character;
    int characterASCIINew = characterASCII + key;
    char characterNew;
    int padding = 0;

    // [65, 90] [97, 122]
    if (characterASCII >= 65 && characterASCII <= 90)
    {
        padding = 65;
    } else if (characterASCII >= 97 && characterASCII <= 122)
    {
        padding = 97;
    } else {
        return character;
    }

    return (characterASCII - padding + key) % 26 + padding;

    if (characterASCII >= 65 && characterASCII <= 90)
    {
        while (characterASCIINew > 90)
        {
            characterASCIINew -= 26;
        }
        characterNew = characterASCIINew;
        return characterNew;
    }
    else if (characterASCII >= 97 && characterASCII <= 122)
    {
        while (characterASCIINew > 122)
        {
            characterASCIINew -= 26;
        }
        characterNew = characterASCIINew;
        return characterNew;
    }
    else
    {
        return character;
    }

}