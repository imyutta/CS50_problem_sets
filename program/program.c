#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";

    char *c = "HI!";
    char *p = &s[0];
    
    printf("%p\n", p);
    printf("%p\n", s);
}