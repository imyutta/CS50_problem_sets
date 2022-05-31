#include <stdio.h>
#include <cs50.h>

int main() {
  int yourAge = 30;
  char date[] = "Today is June 1st!\n";
  char day = get_char("Is it a new day today? y/n\n");
  if (day == 'y' || day == 'Y') {
    date[14] = '2';
    date[15] = 'n';
    date[16] = 'd';
    printf("%s", date);
    printf("You are %i!\n", yourAge += 1);
    printf("Happy birthday!\n");
    printf("I love you!\n");

  }





}