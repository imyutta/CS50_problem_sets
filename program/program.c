#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{

}

int collatz(int n)
{

    int steps = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            steps++;
        }
        else
        {
            n = 3 * n + 1;
            step++;
        }
    }
    return steps;

}