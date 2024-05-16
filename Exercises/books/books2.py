import csv

books = []

#add three books to your shelf
for i in range(3):
    book = dict()
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ")

    books.append(book)


with open("books.csv") as file:
    fieldnames = ['title', 'autor']
    file_writer = csv.DictWriter(file, fieldnames=fieldnames)
    file_writer.writeheader()

    for b in book:
        file_writer.writerow({b.title, b.author})

for book in books:
    print(book["title"])