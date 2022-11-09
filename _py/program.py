import csv
from cs50 import get_string

file = open("phonebook.csv", "a")

name = get_string("Name: ")
number = get_string("Name: ")

writer = csv.writer(file)
writer.writerow([name, number])

file.close()
