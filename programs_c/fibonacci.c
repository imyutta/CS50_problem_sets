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

    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}