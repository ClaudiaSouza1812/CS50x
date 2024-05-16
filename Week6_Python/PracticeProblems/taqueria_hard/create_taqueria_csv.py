import csv

def main():

    menu = []

    for item in range(9):
        item = dict()
        item["food"] = input("Food: ").strip().title()
        item["price"] = "{:.2f}".format(float(input("Price: ")))
        menu.append(item)

    with open("taqueria.csv", "w", encoding = "utf-8") as csv_file:
        file_writer = csv.DictWriter(csv_file, fieldnames = ["food", "price"])
        file_writer.writeheader()

        for item in menu:
            file_writer.writerow(item)

    for item in menu:
        print(item)


main()