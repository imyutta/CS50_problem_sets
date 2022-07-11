// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 456976;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // number of letters in alphabet
    int letters = 26;

    // prepare to serch for a hash-number
    unsigned int hash_number = 0;
    int alphabet_number = 0;
    int power = 0;

    // find an alphabet number for the first letter
    // find a hash-number for the first letter
    // then if there are other letters left, adjust the hash-number
    for (int i = 0; i < 4; i++)
    {
        power = 3 - i;
        alphabet_number = toupper(word[i]) - 'A';
        hash_number += pow(letters, power) * alphabet_number;
        if (isalpha(word[i]) == false)
        {
            break;
        }
    }
    return hash_number;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // prepare to
    char buffer[LENGTH + 1];

    //open a dictionary
    //check if opened correctly
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    //copy from a dictionary into buffer by one word
//    while (fread(&buffer), sizeof(LENGTH + 1), 1, dictionary_file)
    fscanf(dictionary_file, "%s", buffer)
    node *n = malloc(sizeof(node));
    strcopy(n-word, "...");
    n->next = NULL;

    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
