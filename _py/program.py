from cs50 import get_string

people = {
    "YA": "480",
    "EA": "650"
}

name = get_string("Name: ")
if name in people:
    number = people[name]
    print(f"Number: {number}")