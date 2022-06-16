#include <cs50.h>
#include <stdio.h>

int main(void)
{
char *c = "HI!";
*c = 'c';
printf("%c\n", *c);
}