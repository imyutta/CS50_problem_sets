#include <cs50.h>
#include <stdio.h>

int collatz(int n, int steps);

int main(void)
{
    int n = get_int("n= ");
    int steps = 0;
    int allSteps = collatz(n, steps);
    printf("Steps = %i\n", allSteps);
}

int collatz(int n, int steps)
{

    if (n == 1)
    {
        return steps = 0;
    }
    else if (n % 2 == 0)
    {
        n/2
        steps++
        return steps + collatz(n / 2);
    }
    else
    {

        return steps + collatz(3 * n + 1);
    }

}