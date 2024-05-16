# implements a registration form using a select menu, storing registrants in a dictionary, with error messages

#import needed libraries and functions
from cs50 import SQL
from flask import Flask, render_template, request, redirect

#turn this file into a Flask application
app = Flask(__name__)

# make a SQL database to store the registrants
db = SQL("sqlite:///froshims.db")

# make a dictionary to store the registrants
#REGISTRANTS = {}

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

# declare the decorator with the root defined every time the user visits the default page of the website
# define a function that will determine the actions
# determine the file that the server will send to the browser and the variable with list of sports that will be used
@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

# declare the decorator with the root defined every time the user visits the default page of the website
# define a function that will determine the actions
# determine the file that the server will send to the browser
@app.route("/deregister", methods=["POST"])
def deregister():
    #forget registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

# declare the decorator with the root defined every time the user visits the default page of the website
# define a function that will determine the actions
# determine the file that the server will send to the browser
@app.route("/register", methods=["POST"])
def register():
    #validate submission
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html")

    #remember registrant
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    #confirm registration
    return redirect("/registrants")

    #REGISTRANTS[name] = sport
    #return render_template("success.html")

# declare the decorator with the root defined every time the user visits the default page of the website
# define a function that will determine the actions
# determine the file that the server will send to the browser
@app.route("/registrants")
def registrants_dic():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
