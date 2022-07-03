#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


// int main()
// {

// typedef struct node
// {
//     int number;
//     struct node *next;
// }
// node;
// }

int main(void)
{
    // List of size 0
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;

    // Update list to point to new node
    list = n;
}
