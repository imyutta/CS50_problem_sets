#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long int card_number = get_long("What is your card number? ");

// underline every other digit, starting with the number's second-to-last digit
// multiply each of the underlined digits by 2
    const int N = 10;
    //for
    int a1 = ((card_number % N) * 2);
    printf("%i\n", a1);
    int a3 = (floor(card_number % 1000)/ 100)) * 2;

    int a5 = (floor((card_number % pow(N, 5)) / pow(N, 4))) * 2;

    int a7 = (floor((card_number % pow(N, 7)) / pow(N, 6))) * 2;

    int a9 = (floor((card_number % pow(N, 9)) / pow(N, 8))) * 2;

    int a11 = (floor((card_number % pow(N, 11)) / pow(N, 10))) * 2;

    int a13 = (floor((card_number % pow(N, 13)) / pow(N, 12))) * 2;

    int a15 = (floor((card_number % pow(N, 15)) / pow(N, 14))) * 2;
    printf("%i\n", a15);







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