
def main():
    height = get_height()

    for i in range(height):
        spaces = height - i - 1
        sharps = i + 1
        print("_" * spaces, end = "")
        print("#" * sharps, end = "")
        print()

# second option of code:
        # for j in range(height - i - 1):
        #     print("_", end = "")
        # for k in range(i + 1):
        #     print("#", end = "")
        # print()

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                break
        except ValueError:
            print("it should be an integer between 1 and 8 inclusive")
    return n

main()


