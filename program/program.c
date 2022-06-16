#include <stdio.h>
#include <cs50.h>

int main(void)
{
//     char *pk = "HI!";
//     printf("%c\n", *pk);
//     printf("%s\n", pk);
//     printf("%p\n", pk);
//
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (*s == *t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}