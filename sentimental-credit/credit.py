# TODO
from cs50 import get_int

# promt user for a card number
card_number = get_int("Number: ")

# every other digit, starting with the number’s second-to-last digit:
every_other_digit = 0

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