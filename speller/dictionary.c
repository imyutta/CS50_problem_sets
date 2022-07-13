// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <strings.h>
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
unsigned int dictionary_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //find hash number
    unsigned int hash_number = hash(word);

    //make temporary node variable
    node *tmp = table[hash_number];

    //compare the word and the word in the node of our hash table
    int is_same;

    while (true)
    {
        if (tmp == NULL)
        {
            return false;
        }
        else
        {
            is_same = strcasecmp(tmp->word, word);
            if (is_same == 0)
            {
                return true;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // number of letters in alphabet
    unsigned int letters = 26;

    // prepare to serch for a hash-number
    unsigned int hash_number = 0;
    unsigned int alphabet_number = 0;
    unsigned int power = 0;

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
    // prepare to scanning
    char buffer[LENGTH + 1];
    unsigned int hash_number = 0;

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
        dictionary_size ++;
    }


    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);

        }
    }
    printf("UNLOAD cursor is free");
    return true;
}
