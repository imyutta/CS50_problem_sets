#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, i, p, j;

// Ask user for a positive number from 1 to 8
    do
    {
        h = get_int("Height: \n");
    }
    while (h < 1 || h > 8);

//the amount of lines will be
    for (i = 0; i < h; i++)
    {
//the amount of #'s (line i, first mount) will be

//printing first dots "     "
        for (j = 0; j < (h - p); j++)
        {
            printf(" ");
        }
//printing first #'s
        // while (p > 0)
        // {
        //     printf("#");
        //     p--;
        // }
        for (p = i + 1; p > 0; p--)
        {
            printf("#");
        }
//printing second dots ".."
        printf("  ");

//printing second #'s
        // while (z > 0)
        // {
        //     printf("#");
        //     z--;
        // }
        for (p = i + 1; p > 0; p--)
        {
            printf("#");
        }
        printf("\n");
    }
}