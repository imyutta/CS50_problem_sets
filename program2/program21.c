#include <stdio.h>
#include <cs50.h>

int main() {
  int yourAge = 30;
  char date[] = "Today is June 01!\n";
  char day = get_char("Is it June 2nd today? y/n\n");
  if (day == 'y' || day == 'Y') {
    date[15] = '2';
    printf("%s", date);
    printf("You are "%i", yourAge+=1);
    printf("Happy birthday!\n");
    printf("I love you!\n");
    printf("P.S. you spoiled all the gifts that I'd come up with");

  }





}