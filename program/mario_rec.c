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

        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
           printf("#");
           return mario(n + 1);
        }

}