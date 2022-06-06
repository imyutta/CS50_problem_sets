#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool isKeyAlpha(string key);
bool isKeyUnrepeated(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
//check if the key is valid
    string key = argv[1];
    //check if argc = 2
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
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

    //prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, key);

    //print ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;



}

//the function checks if the key characters are all letters
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

//the function checks if the key characters are unrepeated
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

//the function encrypts plaintext to ciphertext
string encrypt(string plaintext, string key)
{
    string ciphertext = plaintext;
    int padding;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int plaintextASCII = plaintext[i];
        if (plaintextASCII >= 65 && plaintextASCII <= 90)
        {
            padding = 65;
            int plaintextASCIInew = plaintextASCII - padding;
            ciphertext[i] = toupper(key[i]);
        }
        else if (plaintextASCII >= 97 && plaintextASCII <= 122)
        {
            padding = 97;
            ciphertext[i] = tolower(key[i]);
        }
    }
    return ciphertext;
}
