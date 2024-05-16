# create a dictionary menu, with foods as keys and prices as values
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

# an object to calculate the total value of the orders
total = 0.00

# prompt user the orders, exclude the spaces before and after the words,
# make all words titled, check if the order is on the menu, if it is,
# update the total and print it, else, ignore the word prompted, if the user
# insert control d, print a line and break the program
while True:
    try:
        order = input("Item: ").title().strip()
        if order in menu:
            total += float(menu[order])
            print(f"Total: ${total:.2f}")
    except EOFError:
        print()
        break

