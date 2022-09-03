import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

if "ron" in names:
    print("Found")
    sys.exit(0)

print("Not found")
sys.exit(1)