#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char word[LONGEST_WORD + 1];
    struct node *next;
}
node;

node *hash_table[NUMBER_OF_BUCKETS];

int main()
{

}
