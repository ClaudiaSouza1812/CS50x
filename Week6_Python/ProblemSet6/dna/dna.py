# import needed libraries
import csv
import sys


def main():
    # TODO: Check for command-line usage, which means checking if the two
    # file names was wrote after the program name
    if len(sys.argv) != 3:
        print("Usage: python dna.py DATABASE SEQUENCE")
        sys.exit(1)

    # TODO: Read DNA sequence file into a variable, after that this file will be closed,
    # because we have alredy store its value into a variable
    with open(sys.argv[2], "r") as dna_file:
        sequence = dna_file.read()

    # TODO: Read database file into a variable that will read all the rows of a dictionary,
    # this file will be open until the end of the program, because the row are read one by
    # one, this way every the algorithm that follows needs to be in the scope of this function
    with open(sys.argv[1], "r") as database_file:
        data_reader = csv.DictReader(database_file)

    # TODO: Find longest match of each STR in DNA sequence, create a dictionary object to store
    # each str name and its longest sequence, determine the subsequences of str's by taking
    # the data_reader fieldnames, starting by its second position. Do a loop to populate the
    # dictionary with the str name followed by its longest sequence value
        str_list = dict()
        subsequence = data_reader.fieldnames[1:]
        n = len(subsequence)

        for index in range(n):
            str_list[subsequence[index]] = longest_match(sequence, subsequence[index])

    # TODO: Check database for matching profiles, calling the match profiles function
        match_prof(subsequence, data_reader, str_list)


def longest_match(sequence, subsequence):
    counter = 0
    # will count the sequence of str's until it is interrupt for another str, by multiplying
    # the current str by the counter plus one in each turn
    while subsequence * (counter + 1) in sequence:
        counter += 1
    return str(counter)


def match_prof(subsequence, data_reader, str_list):
    # for each row (profile) in data_reader in range of subsequence (str) length, check if all str's
    # values in str_list match with all the str's values of someones profile in the data reader, if
    # its so, print the person name, otherwise, prints "no match"
    str = subsequence
    n = len(str)
    for row in data_reader:
        counter = 0
        for index in range(n):
            if row[str[index]] == str_list[str[index]]:
                counter += 1
                if counter == n:
                    print(row["name"])
                    sys.exit(0)
            else:
                break
    print("No match")
    sys.exit(0)


main()
