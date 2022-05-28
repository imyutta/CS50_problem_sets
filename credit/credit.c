#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long int card_number = get_long("What is your card number? ");

// underline every other digit, starting with the number's second-to-last digit
// multiply each of the underlined digits by 2
    for 
    int a1 = ((card_number % 10) * 2);
    printf("%i\n", a1);
    int a2 = (floor((card_number % 1000) / 100)) * 2;
    printf("%i\n", a2);
    int a3 = (floor((card_number % 100000) / 10000)) *2;





// sum1: add those products' digits together

// sum2: sum of digits thah weren't multiplied by 2

// sum3 = sum1+sum2

// If sum2% = 0 check this
    // the amount of digits=15?
    //the first digit=34 or 37?
    // print American express

    //the amount of numbers = 16?
    // the first numbers are 51,52,53,54 or 55?
    // print mastercard

    // the amount of numbers is 13?
    // the first is 4?
    // print visa

// If sum2% !=0 print INVALID

}