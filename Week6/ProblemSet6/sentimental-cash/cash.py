from cs50 import get_float
from math import floor


def main():

    # Ask how many cents the customer is owed
    change = 0
    while change <= 0:
        change = get_float("Change owed: ")
    change = change * 100

    # Calculate the number of quarters to give the customer
    quarters = calc_quarters(change)
    change = round(change - quarters * 25, 2)

    # Calculate the number of dimes to give the customer
    dimes = calc_dimes(change)
    change = round(change - dimes * 10, 2)

    # Calculate the number of nickels to give the customer
    nickels = calc_nickels(change)
    change = round(change - nickels * 5, 2)

    # Calculate the number of pennies to give the customer
    pennies = calc_pennies(change)
    change = round(change - pennies * 1, 2)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    print(f"{coins}")


def calc_quarters(change):
    n = floor(change / 25)
    return n


def calc_dimes(change):
    n = floor(change / 10)
    return n


def calc_nickels(change):
    n = floor(change / 5)
    return n


def calc_pennies(change):
    n = floor(change / 1)
    return n


main()