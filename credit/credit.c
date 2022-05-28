#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long int card_number = get_long("What is your card number? ");

// underline every other digit, starting with the number's second-to-last digit
// multiply each of the underlined digits by 2
    long int n = 10;
    int digit2, sum1;

    do
    {
    digit2 = (floor((card_number % (n * 10)) / n)) * 2;
    n *= 100;
    printf("%i\n", digit2);

    //sum1 = digit2
    }
    while (n <= 100000000000000);


    // ne rabotaet int a15 = (floor((card_number % pow(N, 15)) / pow(N, 14))) * 2;
    // ne rabotaet while (n <= pow(n,14));
    // printf("%i\n", a15);




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