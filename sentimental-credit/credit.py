# TODO
from cs50 import get_int, get_string

def main():
# promt user for a card number
    card_number = get_string("Number: ")

    if validation_check(card_number):
        print("valid number")
        return 0
    else:
        print("invalid number")
        return 1


def validation_check(x):
    sum = 0
    if len(x) % 2 == 0:
        x = int(x)
        limit_1 = x - 1
        for i in range(0, limit_1, 2):
            multiplied_digit = i * 2
            sum += multiplied_digit % 10
            sum += multiplied_digit // 10
        for i in range(1, x, 2):
            sum += i
        if sum % 10 == 0:
            return True
        else:
            return False
    else:
        x = int(x)
        limit_1 = x - 1
        for i in range(1, limit_1, 2):
            multiplied_digit = i * 2
            sum += multiplied_digit % 10
            sum += multiplied_digit // 10
        for i in range(0, x, 2):
            sum += i
        if sum % 10 == 0:
            return True
        else:
            return False

main()



# underline every other digit, starting with the number’s second-to-last digit:


# multiply each of the underlined digits by 2

# add those products’ digits (i.e., not the products themselves) together:

# add that sum to the sum of the digits that weren’t multiplied by 2 (starting from the end):

# if the last digit is 0 - the number is ligit







