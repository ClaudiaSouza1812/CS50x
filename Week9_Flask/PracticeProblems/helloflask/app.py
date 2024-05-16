# import libraries, functions and classes
from flask import Flask, render_template, request

# make a Flask application
app = Flask(__name__)

# ensure templates are auto reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# configure the route for the homepage and its function
@app.route("/", methods=["GET", "POST"])
def index():
    # ensure proper input and the rendering of the corresponding file
    if request.method == "GET" or request.form.get("color") == None:
        return render_template("index.html")
    else:
        # for debbug sake
        print("Form submitted!")

        # store the user's choice in a variable and return the page with the chosen color
        color = request.form.get("color")
        return render_template("color.html", color=color)
