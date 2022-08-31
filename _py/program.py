
try:
    x = int(input("x: "))
except ValueError:
    print("That is not an int!")
    exit()
try:
    y = int(input("y: "))
except ValueError:
    print("Not an int")
    exit()

z = x / y

print(f"{z:.50f}")