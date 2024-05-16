import csv
import sys

def main():

    print("Please, type your order")
    print("Press control-d when you finish")

    with open("taqueria.csv", "r") as csv_file:
        file_reader = csv.DictReader(csv_file)

        menu = []
        item = dict()
        for row in file_reader:
            item = row
            menu.append(item)

    total = 0.00
    c = 0
    while True:
        try:
            order = input("Item: ").title().strip()
            for food in menu:
                if order == food["food"]:
                    total += float(food["price"])
                    print(f"Total: ${total:.2f}")
                    break
                else:
                    c += 1
                if c == 9:
                    c = 0
                    print("Type at least one item of the menu")

        except EOFError:
            print()
            print(f"Total: ${total:.2f}")
            sys.exit(0)

main()