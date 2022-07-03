#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{

typedef struct node
{
    int number;
    struct node *next;
}
node;

n = malloc(sizeof(node));
if ( n != NULL)
{
    n->number = 2;
    n->next = NULL;
}

}
