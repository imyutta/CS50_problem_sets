
def main():
    height = get_height()

    for i in range(height):
        for j in range(height - i - 1):
            print("_", end = "")
        for k in range(i + 1):
            print("#", end = "")
        print()


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                break
        except ValueError:
            print("it should be an integer from 1 to 8 inclusive")
    return n

main()


#  type(height) == int and height > 0 and height < 8: