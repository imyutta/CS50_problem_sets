#include <stdio.h>
#include <string.h>

struct myStructure
{
  int myNum;
  char myLetter;
  char myString[30];
};

int main() {
  struct myStructure s1 = {13, 'B', "Some text"};
  struct myStructure s2;
  s2=s1;
  s2.myNum = 30;

  printf("%d, %c, %s\n", s2.myNum, s2.myLetter, s2.myString);


  }





