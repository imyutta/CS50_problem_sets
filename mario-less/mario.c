#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        i = get_int("Pyramid height: ");
    }
    while (h<1 || h>8);

    for (i=0; i<h; i++)
    {
        for (j=0; j<h; j++)
        {
            printf (" ");
        }
    }
}