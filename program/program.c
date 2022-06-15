#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 65;
    int *m = &n;
    printf("%p\n", m);
    printf("%c\n", *m);

}