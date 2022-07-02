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
    int *list = malloc(5 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    list[3] = 4;
    list[4] = 5;

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%i\n", list[i]);
    // }

    free(list);
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // list = malloc(4 * sizeof(int));
    // list[3] = 4;
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%i\n", list[i]);
    // }
}

