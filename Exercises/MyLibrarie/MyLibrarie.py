import csv
from cs50 import SQL


# Example of how to come up with data using a csv file and Python only
with open("favorites.csv", "r") as csv_file:
    csv_reader = csv.DictReader(csv_file)
    counts = dict
    for row in csv_reader:
        favorite = row["name"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1
"""
# lambda function its the same as this following function:
def get_value(language):
    return counts[language]
"""
favorite = input("Favorite: ").title()
if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")

for favorite in sorted(counts, key = lambda problem: counts[problem], reverse = True):
    print(f"{favorite}: {counts[favorite]}")



# Example of using SQL with Python
db = SQL("sqlite:///favorites.db")
favorite = input("Favorite: ").title()
rows = db.execute("SELECT Count(*) AS n FROM favorites WHERE problem = ?", "%" + favorite + "%")
print(rows[0]["n"])


# Example of Instagram or Facebook update number of likes
db.execute("BEGIN TRANSACTION")
rows = db.execute("SELECT likes FROM posts WHERE id = ?", id)
likes = rows[0]["likes"]
db.execute("UPDATE posts SET likes = ? WHERE id = ?", likes + 1, id)
db.execute("COMMIT")



