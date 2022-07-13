height = input("Height: ")

for i in [1, 2, 3, 4]:
    for j in range(height - i):
    print("_")
    for k in range(i):
    print("#")