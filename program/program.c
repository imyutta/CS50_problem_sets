#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = "HI!";
    char c = s[0];
    char *p = &c;

    printf("%s\n", s);
    printf("%p\n", s);
    printf("%p\n", p);

}