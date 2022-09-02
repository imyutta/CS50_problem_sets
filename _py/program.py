from cs50 import get_string

before = get_string("before: ")
print("After: ", end = "")

for c in before:
    print(c.upper(), end="")
print()