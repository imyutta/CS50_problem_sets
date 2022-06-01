#include <stdio.h>
#include <cs50.h>

struct myStructure
{
  int myNum;
  char myLetter;
};

int main() {
  struct myStructure s1;
  s1.myNum = 13;
  s1.myLetter = 'B';

  printf("my number: %d\n", s1.myNum);
  printf("my letter: %c\n", s1.myLetter);

  }





