
from cs50 import get_float

# ask user how much change he needs
# output the minimum number of coins possible
def main():
    # change in cents will be
    change = get_change() * 100
    coins = 0

    # calculate quarters, dimes, nickels, pennies
    # calculate sum of coins
    for i in [25, 10, 5, 1]:
        quarters = int(change / i)
        change = change % i
        coins += quarters
    print(int(coins))


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