#include <stdio.h>
#include <cs50.h>

struct myStructure
{
  int myNum;
  char myLetter;
  char myString[30];
};

int main() {
  struct myStructure s1;
  strcpy(s1.myString, "Some text");


  printf("my string: %s\n", s1.myString);


  }





