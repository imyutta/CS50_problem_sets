#include <cs50.h>
#include <stdio.h>


int fibonacci(int n);

int main(void)
{
    int n = get_int("n= ");

    int answer = fibonacci(n);
    printf("answer = %i\n", answer);
}

int fibonacci(int n)
{
    0
    1
    
    if (n == 1)
        return 0;
    else if ((n % 2) == 0)
        return 1 + collatz(n/2);
    else
        return 1 + collatz(3*n+1);
}