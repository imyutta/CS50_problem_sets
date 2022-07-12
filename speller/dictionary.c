// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
const unsigned int DICTIONARY_SIZE = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //find hash number
    int hash_number = hash(word);

    //make temporary node variable
    int *tmp = NULL;
    tmp = table[hash_number];

    //compare the word and the word in the node of our hash table
    bool is_same;

    while (true)
    {
        is_same = strcasecmp(tmp->word, word);
        if (is_same == true)
        {
            return true;
        }
        else if (tmp->next != NULL)
        {
        tmp = tmp->next;
        }
        else if
    }


    return true;
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
        if (isalpha(word[i]) || (word[i] == '\''))
        {
            alphabet_number = abs(toupper(word[i]) - 'A');
            hash_number += pow(letters, power) * alphabet_number;
        }
        else
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
    int hash_number = 0;

    //open a dictionary
    //check if opened correctly
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    //copy from a dictionary into buffer by one word
    while (fscanf(dictionary_file, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not scan %s for words\n", dictionary);
            return false;
        }

        //create a node
        //copy the word from buffer to node
        strcpy(n->word, buffer);
        n->next = NULL;

        //find hash-number
        //insert the word into the hash table
        hash_number = hash(buffer);
        if (table[hash_number] == NULL)
        {
            table[hash_number] = n;
        }
        else
        {
            n->next = table[hash_number];
            table[hash_number] = n;
        }
        DICTIONARY_SIZE ++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return DICTIONARY_SIZE;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
