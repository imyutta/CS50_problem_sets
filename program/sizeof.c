#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  // Declare an array of four integers:
  int myNumbers[4];

  // Add elements to it
  myNumbers[0] = 25;
  myNumbers[1] = 50;
  myNumbers[2] = 75;
  myNumbers[3] = 75;


  printf("size of int %lu\n", sizeof(myNumbers));


    char s[] = "HI!";
    printf("%s \n", s);

    printf("size of char %lu\n", sizeof(s));
}