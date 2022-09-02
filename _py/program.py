import sys

if len(sys.argv) !=2:
    print("missing arg")
    exit(1)

print(f"hello, {sys.argv[1]}")
exit(0)
