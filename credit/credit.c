#include <cs50.h>
#include <stdio.h>
#include <math.h>

int int_length(long int);


int main(void)
{
  long int card_number = get_long("What is your card number? ");

  long int n;
  int mult_digit2;
  int sum_mult_digit2 = 0;
  int sum_digit1 = 0;

  for (n=10; n <= 1000000000000000; n*=100)
  {

    mult_digit2 = (floor((card_number % (n * 10)) / n)) * 2;    // multiply every 2nd digit (counting from the 2nd from the end) by 2
    sum_mult_digit2 += (mult_digit2 % 10) + (floor(mult_digit2 / 10));    // add those mult_digits2 together (not the numbers, but their digits)

  }


  for (n=1; n<= 100000000000000; n *= 100)
  {
    sum_digit1 = sum_digit1 + (floor (card_number % (n*10)) / n);     // sum of every 2nd digit (counting from the 1st!!! from the end)
  }


  int lenght = int_length(card_number);
  int first_two_digits = get_first_digets(card_number, 2);
  int first_digit = get_first_digets(card_number, 1);
  bool is_card_hash_valid = (sum_mult_digit2 + sum_digit1) % 10 == 0;

  if (!is_card_hash_valid) {
    printf("INVALID\n");
    return 0;
  }

  switch (true)
  {
    case
  }


  //checking whether it is AMEX or MASTERCARD or VISA
  if ((sum_mult_digit2 + sum_digit1) % 10 == 0 && int_length(card_number)==15 && (floor (card_number / 10000000000000) == 34 || floor (card_number / 10000000000000) == 37))
  {
    printf("AMEX\n");
    //the first digit=34 or 37?
  }
  else if ((sum_mult_digit2 + sum_digit1) % 10 ==0 && int_length(card_number)==16 && (floor (card_number / 10000000000000) == 51 || floor (card_number / 10000000000000) == 52 || floor (card_number / 10000000000000) == 53 || floor (card_number / 10000000000000) == 54 || floor (card_number / 10000000000000) == 55))
  {
    printf("MASTERCARD\n");
  }
  else if ((sum_mult_digit2 + sum_digit1)==0 && (int_length(card_number)==13 || int_length(card_number)==16) && floor (card_number / 10000000000000) == 4)
  {
    printf("VISA\n");
  }
  else
  {
    printf("INVALID\n");
  }


    // ne rabotaet while (n <= pow(n,15));


}

int int_length(long int x)
{
  int length = 0;
  while (x > 0)
  {
    x /= 10;
    length += 1;
  }
  return length;
}

int get_first_digets(long int x, int digets)
{
  return floor(x / pow(10, length - digets))
}
