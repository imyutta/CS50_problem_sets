#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = get_int("n= ");
    int steps = collatz(n);
    printf("Steps = %i", steps);
}

int collatz(int n)
{
    int steps;
    if (n == 1)
    {
        return 0;
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