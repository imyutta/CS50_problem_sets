#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = "bgn";

    printf("%c\n", s[0]);

    s[0] = 'B';
    printf("%s\n", s);

    //printf("%c\n", s[0]);

}

