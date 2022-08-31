from cs50 import get_string

s = get_string("agree? ").lower()


if s in ["y", "yes"]:
    print("Agreed")
elif s in ["n", "no"]:
    print("Not agreed")