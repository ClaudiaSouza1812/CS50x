import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name").rsplit()
        # for debug sake
        # print(name)
        date = request.form.get("date").split("-")
        # print(date)
        submit = request.form.get("submit")

        if submit and date[0] != '':
            if not name:
                    message = "Type only letters and select a date"
                    return render_template("birth.html", message=message)
            else:
                w = 0
                for word in name:
                    if word.isalpha():
                        name[w] = word.capitalize()
                        print(name[w])
                        w = w + 1
                        continue
                    else:
                        message = "Type only letters and select a date"
                        return render_template("birth.html", message=message)

                final_name = " ".join(name)
                day = int(date[2])
                month = int(date[1])
                db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?);", final_name, month, day)
                return redirect("/")

        else:
            message = "Type a name and select a date"
            return render_template("birth.html", message=message)
    else:

        # TODO: Display the entries in the database on index.html
        birthdays = db.execute("SELECT * FROM birthdays;")
        return render_template("index.html", birthdays=birthdays)


