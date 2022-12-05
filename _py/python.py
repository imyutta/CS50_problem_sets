import csv

from cs50 import SQL

db = SQL("sqlite:///favorites8.db")

title = input("Title: ").strip()

rows = db.execute("SELECT COUNT(*) AS counter FROM favorites8 WHERE title LIKE ?", title)

row = rows[0]

print(row["counter"])