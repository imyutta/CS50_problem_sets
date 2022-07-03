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

// node *list = NULL;
// node *n = malloc(sizeof(node));
// if (n != NULL)
// {
//     (*n).number = 1;
//     n->next = NULL;
// }
// list = n;
// free(list);
// }

int main(void)
{
    // Dynamically allocate an array of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Assign three numbers to that array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Time passes

    // Resize old array to be of size 4
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    tmp[3] = 4;

    list = tmp;

    free(list);

}


