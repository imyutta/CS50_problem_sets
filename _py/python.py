import csv
import re

#create database
open("fa.db", "w").close()
db = cs50.SQL("sqlite:///favorites8.db")

