
from cs50 import get_float
# ask user how much change he needs

def main():
    change = get_change()
    print(change)



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