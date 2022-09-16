import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: enter two command-line arguments")

    # Read database file into a variable
    database = []
    strs = []

    with open(sys.argv[1]) as file1:
        reader = csv.DictReader(file1)
        # read STRs into a variable called strs
        strs = reader.fieldnames[1:]
        # append all the people to a variable called database
        for x in reader:
            database.append(x)

    # Read DNA sequence file into a variable called sequence
    sequence = {}
    with open(sys.argv[2]) as file2:
        for x in file2:
            sequence = x



    # TODO: Find longest match of each STR in DNA sequence
    longest_match(sequence, STRs[0])
    print(database[-1])


    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
