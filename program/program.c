// #include <cs50.h>
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     string s = "bgn";

//     printf("%c\n", s[0]);

//     s[0] = 'B';
//     printf("%c\n", s[0]);

//     //printf("%c\n", s[0]);

// }

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%c %c %c\n", s[0], s[1], s[2]);
    s = "B";
    printf("%c %i %i\n", s[0], s[1], s[2]);
}