# import the needed libraries
from cs50 import get_string
import string


def main():
    # prompts user a text request;
    text = get_string("Text: ").strip().lower()

    # objects that store the result of the called functions, each of them receives
    # a string argument and returns an integer its results;
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # objects that receives the result of letters and sentences divided by words times 100
    l = (letters / words) * 100
    s = (sentences / words) * 100
    # object that stores the result of Coleman-Liau expression
    index = round((0.0588 * l) - (0.296 * s) - 15.8)

    # prompts user the result based on the value of the index;
    if index > 15:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


# function to count the valid letters of a sentence or word;
def count_letters(text):
    # objectic that stores letters without punctuation and spaces
    letters = text.translate(str.maketrans('', '', string.punctuation)).replace(" ", "")
    # object that store the numer of letters
    n = len(letters)
    return n

    """
    another way to do it:
    n = 0
        for l in text:
            if l.isalpha():
                n += 1
        return n
    """


# function to count the valid words of a sentence;
def count_words(text):
    # objectic that stores words without punctuation in a list;
    words = text.translate(str.maketrans('', '', string.punctuation)).split()
    # object that store the numer of letters founded in the list
    n = len(words)
    return n


# function to count the valid sentences of a text;
def count_sentences(text):
    # a list to store each sentence and 2 counters
    sentences = []
    c = -1
    i = 0

    # a loop to identify the determined punctuation and after that, will check if the previous
    # character is not a punctuation too, if it isn't, will store all the words before it in
    # an object, appending it in the sentences list
    for p in text:
        c += 1
        if p == '.' or p == '!' or p == '?':
            if text[c - 1] not in string.punctuation:
                pieces = text[i:c]
                sentences.append(pieces)
                i = c
    # object that store the numer of sentences founded in the list
    n = len(sentences)
    return n


main()