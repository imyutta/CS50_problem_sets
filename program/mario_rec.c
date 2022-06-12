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

    mario(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");


}
