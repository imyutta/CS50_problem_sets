#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h, line, p, spaces;

// Ask user for a positive number from 1 to 8
    do
    {
        h = get_int("Height: \n");
    }
    while (h < 1 || h > 8);

//the amount of lines will be
    for (line = 0; line < h; line++)
    {

//printing first dots "     "
        for (spaces = 0; spaces < (h - line - 1); spaces++)
        {
            printf(" ");
        }
//printing first #'s
        // while (p > 0)
        // {
        //     printf("#");
        //     p--;
        // }
        for (p = line + 1; p > 0; p--)
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
        for (p = line + 1; p > 0; p--)
        {
            printf("#");
        }
        printf("\n");
    }
}