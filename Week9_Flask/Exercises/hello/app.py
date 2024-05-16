from flask import Flask, render_template, request

app = Flask(__name__)


# the GET method will get the user information and the POST method will show it
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))

