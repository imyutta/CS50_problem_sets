#include <cs50.h>
#include <stdio.h>

int main(void)
{
int k = 5;
printf("%d\n", k);

int *pk = &k;
*pk = 35;
printf("%d\n", *pk);




}