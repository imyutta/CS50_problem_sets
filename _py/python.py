import csv
import re
titles = {}
counter = 0

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        #if re.search("^(OFFICE|THE OFFICE)$", title):
           # counter += 1
        titles = title

#print(f"Number of people who like The Office: {counter}")
print(title)

import csv

titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["title"].strip().upper()
        if not title in titles:
            titles[title] = 0
        titles[title] += 1

for title in sorted(titles):
    print(title, titles[title])