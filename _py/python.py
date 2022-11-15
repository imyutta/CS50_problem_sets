import csv
import re

title = input("Title: ").strip().upper()
counter = 0

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        if re.search("^(OFFICE|THE.OFFICE)$", title):
            counter += 1
        titles = title

print(f"Number of people who like The Office: {counter}")
