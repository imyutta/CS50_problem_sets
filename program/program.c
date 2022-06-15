#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    char *p = "HI!";
    char *n = &*p[0];
    printf("%p", n);

}