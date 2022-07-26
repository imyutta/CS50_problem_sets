# TODO
# from cs50 import get_int

# promt user for a card number
card_number = input("Number: ")

# name second_digit means that we start counting from the end
# name first_digit means that we start counting from the end

second_digits = 0
second_digits_sum = 0
first_digits = 0
first_digits_sum = 0

if card_number % 2 == 0:
    # multiply every 2nd digit (counting from the 2nd from the end) by 2
    for i in card_number:
        int(i) * 2


# add those mult_digits2 together (not the numbers, but their digits)

# find sum of every 2nd digit (counting from the 1st!!! from the end)