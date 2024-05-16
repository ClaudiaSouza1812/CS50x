# import the needed libraries
from cs50 import get_string


def main():
    # prompt to user the card number
    # get the card number length
    card = get_string("Card number: ")
    length = len(card)

    # run Luhns algorithm function
    # run first two digits card function
    # run flag identification function
    check_luhns = luhns_algo(card, length)
    check_card = card_algo(card, length)
    check_flag = flag_algo(check_luhns, check_card, length)

    # print the card flag
    print(check_flag)


# function that checks if a card number is valid
def luhns_algo(card, length):
    # tranform the string card number in to an array of integers
    card = [int(x) for x in card[0:length]]
    sum_odd, sum_even, sum = 0, 0, 0
    # will loop through the array from backwards until reaches zero, iterating from two in two numbers
    for index in range(length, 0, -2):
        # takes all the odd position values from backwards and multiply them by 2
        index1 = index - 2
        if index1 >= 0:
            odd = card[index1] * 2
            # split and sum all values above 9
            if odd > 9:
                while odd > 0:
                    sum = sum + odd % 10
                    odd = int(odd / 10)
                odd = sum
                sum = 0
                # sum all the odd products
            sum_odd = sum_odd + odd
        # takes all even position values from backwards and sum them
        index2 = index - 1
        if index2 >= 0:
            even = card[index2]
            sum_even = sum_even + even
    # sums the total of odds and evens
    total = sum_odd + sum_even
    # return the last digit of total
    last_number = total % 10

    return last_number


# return the 2 first digits of credit card number
def card_algo(card, length):
    n = 2
    # make string into integer
    card = int(card)
    # subtract from backwards the card numbers until it reaches the 2 first digits
    while length > n:
        card = int(card / 10)
        length -= 1
    digits = card
    return digits


# determine to wich credit card flag the credit card number belongs
def flag_algo(check_luhns, check_card, length):
    # if the card number is valid according to luhns formula, it will the the card length
    # and the first 2 digits, returning its flag
    if check_luhns == 0:
        if length == 13 or length == 16:
            if check_card > 39 and check_card < 50:
                return "VISA"
            elif check_card > 50 and check_card < 56:
                return "MASTERCARD"
            else:
                return "INVALID"
        elif length == 15:
            if check_card == 34 or check_card == 37:
                return "AMEX"
            else:
                return "INVALID"
        else:
            return "INVALID"
    else:
        return "INVALID"


main()