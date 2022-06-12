#include <cs50.h>
#include <stdio.h>


void mario(int n);

int main(void)
{
    int n = get_int("height= ");
    mario(n);
}

void mario(int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");


}
