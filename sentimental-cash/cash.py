
from cs50 import get_float

# ask user how much change he needs
# output the minimum number of coins possible
def main():
    # change in cents will be
    change = get_change() * 100


    # calculate quarters
    quarters = change / 25
    print(quarters)
    change = change % 25

    dimes = change / 10
    change = change % 10

    nickels = change / 5
    change = change % 5

    pennies = change

    # calculate minimum number of coins
    # print it out
    coins = quarters + dimes + nickels + pennies
    print(coins)





# prompt user for a non-negative float number
def get_change():
    while True:
        try:
            n = get_float("Change: ")
            if n >= 0:
                break
        except ValueError:
            print("Please provide a non-negative float number")
    return n

main()