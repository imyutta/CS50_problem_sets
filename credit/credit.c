#include <cs50.h>
#include <stdio.h>
#include <math.h>

int int_length(int card_number);


int main(void)
{
    long int card_number = get_long("What is your card number? ");

    long int n;
    int mult_digit2;
    int sum_mult_digit2 = 0;
    int sum_digit1 = 0;

    for (n=10; n <= 1000000000000000; n*=100)
    {
      // multiply every 2nd digit (counting from the 2nd from the end) by 2
      mult_digit2 = (floor((card_number % (n * 10)) / n)) * 2;

      // sum_mult_digit2: add those mult_digits2 together (not the numbers, but their digits)
      sum_mult_digit2 += (mult_digit2 % 10) + (floor(mult_digit2 / 10));

      // if you need to check: printf("%i, %i\n", mult_digit2, sum_mult_digit2);
    }


      // sum_digit1: sum of every 2nd digit (counting from the 1st!!! from the end)

     for (n=1; n<= 100000000000000; n *= 100)
     {
        sum_digit1 = sum_digit1 + (floor (card_number % (n*10)) / n);
        printf("%i, sum_digit1\n", sum_digit1);
     }

     //checking

     if ((sum_mult_digit2 + sum_digit1)== 0 && int_length(card_number)==15)
     {
       printf("AMEX\n");
    // the amount of digits=15?
    //the first digit=34 or 37?


     }
     else if ((sum_mult_digit2 + sum_digit1)==0 && int_length(card_number)==16)
     {
       printf("MASTERCARD\n");
     }
   //the amount of numbers = 16?
    // the first numbers are 51,52,53,54 or 55?
    // print mastercard

     else if ((sum_mult_digit2 + sum_digit1)==0 && int_length(card_number)==13)
     {
     // the amount of numbers is 13 ..16?
    // the first is 4?
       printf("MASTERCARD\n");
     }

     else
     {
         printf("INVALID\n");
     }




    // ne rabotaet int a15 = (floor((card_number % pow(N, 16)) / pow(N, 15))) * 2;
    // ne rabotaet while (n <= pow(n,15));
    // printf("%i\n", a15);

}

int int_length(int card_number)
{
  int length;
  for (length = 0; card_number > 0; length++)
  {
    card_number /= 10;

  }
  return length;
}
