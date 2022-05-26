#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;

    //Ask user what is the pyramid height?
    do
    {
        h = get_int("Pyramid height: ");
    }
    while (h < 1 || h > 8);


    int i, j, p;

//for each line:
    for (i = 0; i < h; i++)
    {
//the amount of # will be
        p = i + 1;

//the amount of _ will be:
        for (j = 0; j < (h - p); j++)
        {
            printf(" ");
        }

//printing "#"s at the end of the line
        while (p > 0)
        {
            printf("#");
            p--;
        }
//new line
        printf("\n");
    }
}