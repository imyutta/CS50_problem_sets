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


    int i,j,p;


    for (i=0; i<h; i++)
    {
    p=h-1;

           for (j=0; j<p; j++)
           {
               printf(" ");
           }
           printf("#");
    p--;

    }
}