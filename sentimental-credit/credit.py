# TODO
from cs50 import get_string

def main():
# promt user for a card number
    card_number = get_string("Number: ")

# check if it is a valid number
    if not validation_check(card_number):
        print("Invalid number")
        return 1

# find length of the card number
    length = len(card_number)

# find first two digits
    first_digit = card_number[0]
    second_digit = card_number[1]

    if length == 15 and 




def validation_check(x):
# we take every other digit, starting with the number’s second-to-last digit:
# multiply each of the digits by 2
# add those products’ digits (i.e., not the products themselves) together
# add that sum to the sum of the remaining digits (that weren’t multiplied by 2)
    sum = 0
    for i in x[-2::-2]:
        multiplied_digit = int(i) * 2
        sum += multiplied_digit % 10
        sum += multiplied_digit // 10
    for i in x[-1::-2]:
        sum += int(i)


# check if the last digit is 0
    if sum % 10 == 0:
        return True
    else:
        return False

main()


