import csv

from cs50 import SQL

db = SQL("sqlite:///favo.db")
title = input("Title: ").strip()

rows = db.execute("SELECT title FROM favo WHERE title LIKE ?", title)

for row in rows:
    print(row["title"])
    SELECT name FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id  WHERE title = "Toy Story";

