#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int array[100];
    for (int i = 0; i < 100; i++)
    {
        array[i] = i;
        printf("%i = %i\n", i, array[i]);
    }

}