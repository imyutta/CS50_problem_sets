#include <cs50.h>
#include <stdio.h>

int main(void)
{
int k = 5;
int *pk = &k;
printf("%p\n", pk);

int m = 4;
 pk = &m;
printf("%p\n", pk);




}