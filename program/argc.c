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

node *n = malloc(sizeof(node));
if (n != NULL)
{
    (*n).number = 1;
}
node *list = NULL;
free(n);
}


