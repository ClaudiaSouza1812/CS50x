from cs50 import SQL
from flask import Flask, render_template, request
from finance.helpers import random_string
import random

# make a flask application based on this current file;
app = Flask(__name__)

# make the variable to refer to the database using sqlite that will build the conection to the file;
db = SQL("sqlite:///history.db")

# configure the HTML files to auto-reload automatically when i change them;
app.config["TEMPLATES_AUTO_RELOAD"] = True


# make the route to the main page, which is the homepage, and define the GET method for the user access the route
# define the function that will run whenever the user requests the homepage
# if the page number already exists, show the same value showed before
# if the page number not exists, declare a variable that will get the result of a random string with 1000 characters
# return the index.html page and plug into it by the placeholder the value of the string variable
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        page = request.form.get("page")
        try:
            page = int(page)
        except ValueError:
            return render_template("index.html", random_string="Type a positive number")

        if page < 0:
            return render_template("index.html", random_string="Type a positive number")

        db.execute("INSERT INTO history (page) VALUES (?);", page)
        random.seed(page)

    string = random_string(1000)
    rows = db.execute("SELECT * FROM history;")

    return render_template("index.html", random_string=string, history=rows)
