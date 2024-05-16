import csv

books = []

#add three books to your shelf
for i in range(3):
    book = dict()
    book["title"] = input("Title: ").strip().capitalize()
    book["author"] = input("Author: ")

    books.append(book)

    
print(books)