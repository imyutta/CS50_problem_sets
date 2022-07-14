
# while True:
#     height = int(input("Height: "))
#     if type(height) == int and height > 0 and height < 8:
#         break
#     else:
#         print("non valid integer")

# for i in range(height):
#     for j in range(height - i - 1):
#         print("_")
#     for k in range(i):
#         print("#")

def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        n = int(input("Height: "))
        if n > 0:
            break
    return n

main()
