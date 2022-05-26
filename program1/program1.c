#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;
    while (true)
    {
        n=get_int("Size: ");
        if (n>0)
        {
            break;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            printf ("#");
        }
        printf ("\n");
    }

}