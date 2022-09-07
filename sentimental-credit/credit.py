# TODO
from cs50 import get_int, get_string

def main():
# promt user for a card number
    card_number = get_string("Number: ")
    validation_check(card_number)

    # if validation_check(card_number):
    #     print("valid number")

    # else:
    #     print("invalid number")



def validation_check(x):
    sum = 0
    length = len(x)
    if length % 2 == 0:
        index_1 = 0
        index_2 = 1
    else:
        index_1 = 1
        index_2 = 0

    for i in range(index_1, length, 2):
        multiplied_digit = int(i) * 2
        sum += multiplied_digit % 10
        sum += multiplied_digit // 10
    for i in range(index_2, length, 2):
        sum += int(i)
    if sum % 10 == 0:
        print("1")
        return True
    else:
        print("2")
        return False

main()



# underline every other digit, starting with the number’s second-to-last digit:


# multiply each of the underlined digits by 2

# add those products’ digits (i.e., not the products themselves) together:

# add that sum to the sum of the digits that weren’t multiplied by 2 (starting from the end):

# if the last digit is 0 - the number is ligit







