# TODO
from cs50 import get_string

def main():
# promt user for a card number
    card_number = get_string("Number: ")

# check if it is a valid number
    if not validation_check(card_number):
        print("INVALIDff")
        return 1

# check whether it is an American Express, MasterCard, or Visa card number
    if amex(card_number):
        print("AMEX")
        return 0
    if mastercard(card_number):
        print("MASTERCARD")
        return 0

    if visa(card_number):
        print("VISA")
        return 0
    else:
        print("INVALID")
    return 0




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


def amex(a):
# check length of the card number
    length = len(a)
    if length == 15:
        return True
# check the first two digits
    if a[0] != 3:
        return False
    if a[1] != 4 or a[1] != 7:
        return False
    else:
        return True

def mastercard(a):
# check length of the card number
    length = len(a)
    if length != 16:
        return False

# check the first two digits
    if a[0] != 5:
        return False
    if a[1] != 1 or a[1] != 5:
        return False
    else:
        return True

def visa(a):
# check length of the card number
    length = len(a)
    if length != 13 or length != 16:
        return False

# check the first digit
    if a[0] != 4:
        return False
    else:
        return True
main()


