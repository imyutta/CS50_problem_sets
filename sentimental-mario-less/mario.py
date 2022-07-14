height = int()
height = input("Height: ")

for i in range(height):
    for j in range(height - i - 1):
        print("_")
    for k in range(i):
        print("#")
