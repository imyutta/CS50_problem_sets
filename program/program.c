#include <stdio.h>
#include <cs50.h>

int main(void)
{
//     char *pk = "HI!";
//     printf("%c\n", *pk);
//     printf("%s\n", pk);
//     printf("%p\n", pk);
//
string s = get_string("s: ", s);
string t = s;

char *n = s;

t[0] = toupper(t[0]);

printf("s: %s\n",s);
printf("t: %s\n", t);
}