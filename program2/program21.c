#include <stdio.h>

int main ()
{
    char firstName[5];
    printf("enter a first name: \n");
    scanf("%s", firstName);
    printf("Hello %s!\n", firstName);
    printf("%c\n", firstName[6]);


return 0;


}