#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = "HI!";
    char *p = &s[0];

    printf("%p\n", p);
    printf("%p\n", s);

}