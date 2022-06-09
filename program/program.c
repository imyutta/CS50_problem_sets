#include <cs50.h>
#include <stdio.h>

int collatz(int n, );

int main(void)
{
    int n = get_int("n= ");
    int steps = 0;
    int allSteps = collatz(n);
    printf("Steps = %i\n", allSteps);
}

int collatz(int n)
{
    int steps;
    if (n == 1)
    {
        return steps;
    }
    else if (n % 2 == 0)
    {

        steps++;
        return collatz(n / 2);
    }
    else
    {
        steps++;
        return collatz(3 * n + 1);
    }

}