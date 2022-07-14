
from cs50 import get_float

# ask user how much change he needs
# output the minimum number of coins possible
def main():
    change = get_change()
    print(change)
    



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