# TODO
from cs50 import get_int

# promt user for a card number
card_number = get_int("Number: ")

if validation_check(card_number) == false:
    print(Invalid number)
    break


def validation_check(x):
    sum = 0
    if len(x) % 2 == 0:
        for i in range(0, x - 1, 2):
            multiplied_digit = i * 2
            sum += multiplied_digit % 10
            sum += multiplied_digit 


# underline every other digit, starting with the number’s second-to-last digit:
every_other_digit = 0

# multiply each of the underlined digits by 2

# add those products’ digits (i.e., not the products themselves) together:

# add that sum to the sum of the digits that weren’t multiplied by 2 (starting from the end):

# if the last digit is 0 - the number is ligit
    return true
    return false







# name "second_digit" means that we begun counting from the end
# name first_digit means that we start counting from the end


second_digits_sum = 0
first_digit = 0
first_digits_sum = 0

if len(card_number) % 2 == 0:
    # multiply every 2nd digit (counting from the 2nd from the end) by 2
    for i in card_number:
        second_digit = int(i) * 2
        second_digits_sum += (second_digit % 10) + (second_digit / 10)
        print(second_digits_sum)
else:
    print("not even")


# add those mult_digits2 together (not the numbers, but their digits)

# find sum of every 2nd digit (counting from the 1st!!! from the end)