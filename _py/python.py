import csv

from cs50 import SQL

db = sql("sqlite3:///fa1.db")
title = input("Title: ").s