#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // char *pk = "HI!";
    // printf("%c\n", *pk);
    // printf("%s\n", pk);
    // printf("%p\n", pk);

    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);
    printf("my1: %p\n", t);
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(*t);

    printf("my2: %p\n", t);
}
