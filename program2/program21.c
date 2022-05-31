#include <stdio.h>

int main() {
  int yourAge = 30;
  char date[] = "Today is June 01!\n";
  int day = get_int("Is it June 2nd today? yes/no\n");
  date[15] = '2';
  printf("%s", date);


}