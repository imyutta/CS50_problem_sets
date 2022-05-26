#include <cs50.h>
#include <stdio.h>

float discount(float price);

int main(void) {
   float regular = get_float("Regular Price: ");
   float sale = regular * .85;
   printf("Sale Price: %.2f\n", sale);
}

