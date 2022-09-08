# TODO

from cs50 import get_string
import sys

#  Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8

# prompt user for a text
    text = get_string("Text: ")

# find the amount of words
# any sequence of characters separated by spaces should count as a word
    words = 0
    for i in text:
        if i.isspace():
            words += 1
    print(words)


# find the amount of letters
# a letter is any lowercase character from a to z or any uppercase character from A to Z
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    print(letters)

# find the amount of sentences
# any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    sentences = 0
    for i in text:
        if i == "." or i == "!" or i == "?":
            sentences += 1
    print(sentences)



# find L (letters_average) an average amount of letters per 100 words
    letters_average = (letters / words) * 100

# find S (sentences_average) the average number of sentences per 100 words in the text
    sentences_average = (sentences / words) * 100
