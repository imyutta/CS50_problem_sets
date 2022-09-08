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
# we take every other digit
# multiply each of the digits by 2
# add those products’ digits (i.e., not the products themselves) together
# add that sum to the sum of the remaining digits (that weren’t multiplied by 2)
    sum = 0
    for i in x[-2::-2]:
        multiplied_digit = int(i) * 2
        sum += multiplied_digit % 10
        sum += multiplied_digit // 10
    for i in x[-1::-2]:
        sum += x[i]


# # check if the last digit is 0
#     if sum % 10 == 0:
#         print("1")
#         return True
#     else:
#         print("2")
#         return False

main()


