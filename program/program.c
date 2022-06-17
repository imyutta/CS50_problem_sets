#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
//     char *pk = "HI!";
//     printf("%c\n", *pk);
//     printf("%s\n", pk);
//     printf("%p\n", pk);
//


    char *s = "HI!";
    char *p = &*(s+1);
    printf("%p\n", p);
    printf("%p\n", s);
}
