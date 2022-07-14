
while True:
    height = input("Height: ")
    if type(height) == int:
        if height > 0 and height < 8:
            False

for i in range(height):
    for j in range(height - i - 1):
        print("_")
    for k in range(i):
        print("#")
