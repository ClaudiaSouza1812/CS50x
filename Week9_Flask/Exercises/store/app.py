# import the needed libraries
from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# configure app
app = Flask(__name__)

# connect to database
db = SQL("sqlite:///store.db")

# configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# make the route and define its behavior when it is triggered by a Python function
# make a function that create a variable in memory to store all books found in the database
# return the books page with all of books displayed
@app.route("/")
def index():
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)


@app.route("/cart", methods=["GET", "POST"])
def cart():
    # ensure that already exists a cart inside the session, if not, define an empty list
    if "cart" not in session:
        session["cart"] = []

    # POST
    # if the costumer add a book to the cart, declare a variable with the id from books.html form
    # and add it to the cart list inside the session dictionary;
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")

    # GET
    # when in cart.html store in a variable, from database, all books where its id were in the cart
    # and show them to the user
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)
