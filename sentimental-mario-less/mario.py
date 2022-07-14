
while True:
    height = int(input("Height: "))
    print(type(height))
    if type(height) == int:
    # and height > 0 and height < 8:
        break

for i in range(height):
    for j in range(height - i - 1):
        print("_")
    for k in range(i):
        print("#")

