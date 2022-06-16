// #include <stdio.h>

// int main(void)
// {
//     char *pk = "HI!";
//     printf("%c\n", *pk);
//     printf("%s\n", pk);
//     printf("%p\n", pk);
// }

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
}