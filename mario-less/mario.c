#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    do
    {
        i = get_int("Pyramid height: ");
    }
    while (i<1 || i>8);
}