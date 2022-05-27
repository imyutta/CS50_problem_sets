#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h,i;

    // Ask user for a positive number from 1 to 8
    do
    {
      h=get_int("Height: \n");
    }
    while (h <1 || h > 8);

    for (i = 0; i < h; i++)
    {
      
    }
}