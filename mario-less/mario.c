#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Pyramid height: ");
    }
    while (h<1 || h>8);


    int i,j,p;


    for (i=0; i<h; i++)
    {

           for (p=1; p<h; p++)
           {


               for (j=0; j<(h-p); j++)
               {
                   printf(" ");
               }
               printf ("#");
           }

           for (p=)
           printf("#\n");
    p--;

    }
}