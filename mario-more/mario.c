#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, line, p, space;

// Ask user for a positive number from 1 to 8
    do
    {
        height = get_int("Height: \n");
    }
    while (height < 1 || height > 8);

//the amount of lines will be
    for (line = 0; line < height; line++)
    {

//printing first dots "     "
        for (space = 0; space < (height - line - 1); space++)
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