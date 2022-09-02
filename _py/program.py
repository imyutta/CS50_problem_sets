from sys import argv

if len(argv) !=2:
    print("missing arg")
    exit(1)

print(f"hello, {argv[1]}")
exit(0)
