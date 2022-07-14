
while True:
    try:
        
        height = int(input("Height: "))
        if type(height) == int and height > 0 and height < 8:
            break
        else:
            print("non valid integer")

for i in range(height):
    for j in range(height - i - 1):
        print("_")
    for k in range(i):
        print("#")
