#include <stdio.h>

int main() {
  int yourAge = 30;
  char date[] = "Today is June 01!\n";
  date[15] = '2';
  printf("%s", date);


}