import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from decimal import Decimal

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    userId = session["user_id"]
    rows = db.execute("SELECT * FROM wallet WHERE id = ?;", userId)
    print(rows)

    if len(rows) != 0:
        wallet = db.execute(
            "SELECT stock_name, SUM(shares) ASstock_name,shares FROM wallet WHERE id = ? GROUP BY stock_name;",
            userId,
        )
        balance = db.execute("SELECT cash FROM users WHERE id = ?;", userId)
        cash = round(balance[0]["cash"], 2)

        print(wallet, cash)
        grandtotal = 0

        for item in wallet:
            obj = lookup(item["stock_name"])
            item["price"] = round(obj["price"], 2)
            item["total"] = round(int(item["price"]) * item["shares"], 2)
            grandtotal += item["total"]
            item["price"] = usd(item["price"])
            item["total"] = usd(item["total"])

        grandtotal = round(grandtotal + cash, 2)
        print(wallet, grandtotal)

        return render_template(
            "index.html", wallet=wallet, cash=usd(cash), grandtotal=usd(grandtotal)
        )
    else:
        cash = db.execute("SELECT cash FROM users WHERE id = ?;", userId)
        cash = cash[0]["cash"]
        shares = 0
        grandtotal = cash + shares

        return render_template("index.html", cash=usd(cash), grandtotal=usd(grandtotal))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        stockData = lookup(symbol)

        if not symbol or stockData is None:
            return apology("must provide a valid symbol", 400)
        if not shares or not shares.isdigit() or int(shares) < 1:
            return apology("must provide a positive integer", 400)

        shares = int(shares)
        buy = "bought"
        price = stockData["price"]
        userId = session["user_id"]
        cash = db.execute("SELECT cash FROM users WHERE id = ?;", userId)
        cash = cash[0]["cash"]
        transaction_value = price * shares

        if transaction_value > cash:
            return apology(
                "you cannot afford the number of shares at the current price"
            )

        balance = cash - transaction_value
        db.execute(
            "INSERT INTO transactions (stock_name, tran_type, price, units, userId) VALUES (?, ?, ?, ?, ?);",
            symbol,
            buy,
            price,
            shares,
            userId,
        )
        db.execute("UPDATE users SET cash = ? WHERE id = ?;", balance, userId)

        rows = db.execute("SELECT * FROM wallet WHERE id = ?;", userId)
        i = len(rows)
        print(i)
        n = 0

        if len(rows) != 0:
            for item in rows:
                if item["stock_name"] == symbol:
                    units = db.execute(
                        "SELECT shares FROM wallet WHERE id = ? AND stock_name = ?;",
                        userId,
                        symbol,
                    )
                    units = units[0]["shares"]
                    total = units + shares
                    db.execute(
                        "UPDATE wallet SET shares = ? WHERE id = ? AND stock_name = ?;",
                        total,
                        userId,
                        symbol,
                    )
                    break
                if n == i - 1:
                    db.execute(
                        "INSERT INTO wallet (id, stock_name, shares) VALUES (?, ?, ?);",
                        userId,
                        symbol,
                        shares,
                    )
                    break
                n = n + 1
            flash(
                f"Purchased {shares} shares of {symbol} for {usd(transaction_value)}!"
            )
            return redirect("/")
        else:
            db.execute(
                "INSERT INTO wallet (id, stock_name, shares) VALUES (?, ?, ?);",
                userId,
                symbol,
                shares,
            )
        flash(f"Purchased {shares} shares of {symbol} for {usd(transaction_value)}!")
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    userId = session["user_id"]
    history = db.execute(
        "SELECT * FROM transactions WHERE userId = ? ORDER BY id DESC;", userId
    )

    if len(history) == 0:
        return apology(
            "you must have made at least one purchase or sale transaction", 403
        )

    for price in history:
        price["price"] = usd(price["price"])
    
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        username = request.form.get("username")
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["pass_hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        flash("Bem Vindo!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # ensure symbol was submitted
        if not request.form.get("symbol") or lookup(request.form.get("symbol")) == None:
            return apology("the symbol dosen't exist", 400)
        # get the stock data
        stocks = [lookup(request.form.get("symbol"))]
        stocks[0]["price"] = usd(stocks[0]["price"])
        print(stocks)

        return render_template("quoted.html", stocks=stocks)
    else:
        # User reached route via GET (as by requesting a form via GET)
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # forget any user id
    session.clear()
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)
        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)
        # ensure passwords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords do not match", 400)

        # query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?;", request.form.get("username")
        )
        # ensure username isn't in the database already
        if len(rows) != 0:
            return apology("username already exists", 400)

        username = request.form.get("username")
        password = request.form.get("password")
        db.execute(
            "INSERT INTO users (username, pass_hash) VALUES (?, ?);",
            username,
            generate_password_hash(password, method="pbkdf2", salt_length=16),
        )

        # Redirect user to login
        flash("Registered!")
        return redirect("/login")

    else:
        # User reached route via GET (as by requesting a form via GET)
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # ensure symbol was submitted and it is valid
        if not request.form.get("symbol") or lookup(request.form.get("symbol")) is None:
            return apology("you need to select a stock symbol from your portfolio", 400)
        # get user id, the stock symbol and the dict with user shares
        userId = session["user_id"]
        stock_name = request.form.get("symbol")
        obj_shares = db.execute(
            "SELECT shares FROM wallet WHERE id = ? AND stock_name = ?;",
            userId,
            stock_name,
        )
        # set units as the number of user shares and turn into int the desired amount to sell
        units = obj_shares[0]["shares"]
        shares = int(request.form.get("shares"))
        # ensure the valid range of shares owned by the user
        if shares < 1 or shares > units:
            return apology(
                "must provide a positive integer in the range of shares that you own",
                400,
            )
        # set the status of the operation, get stock data, set price and balance of shares
        sell = "sold"
        stockData = lookup(stock_name)
        price = stockData["price"]
        balance = units - shares
        print(balance)
        # insert operation in database into transactions table
        db.execute(
            "INSERT INTO transactions (stock_name, tran_type, price, units, userId) VALUES (?, ?, ?, ?, ?);",
            stock_name,
            sell,
            price,
            shares,
            userId,
        )
        # if user dosen't have shares anymore, delete it from the wallet, otherwise, update it
        if balance == 0:
            db.execute(
                "DELETE FROM wallet WHERE stock_name = ? AND id = ?;",
                stock_name,
                userId,
            )

        else:
            db.execute(
                "UPDATE wallet SET shares = ? WHERE id = ? AND stock_name = ?;",
                balance,
                userId,
                stock_name,
            )
        # set transaction value, get user cash, update user cash adding transaction value
        transaction_value = price * shares
        obj_cash = db.execute("SELECT cash FROM users WHERE id = ?;", userId)
        cash = obj_cash[0]["cash"]
        total_cash = cash + transaction_value
        db.execute("UPDATE users SET cash = ? WHERE id = ?;", total_cash, userId)
        # display a flash message, redirect to index
        flash(f"Sold {shares} shares of {stock_name} for {usd(transaction_value)}!")
        return redirect("/")

    else:
        # User reached route via GET (as by requesting a form via GET)
        # get user id
        userId = session["user_id"]
        rows = db.execute("SELECT * FROM wallet WHERE id = ?;", userId)
        # check if user already has a wallet, if it so, add the stosk prices and show wallet content in sell html
        if rows != 0:
            wallet = db.execute(
                "SELECT stock_name, shares FROM wallet WHERE id = ?;", userId
            )
            print(wallet)

            for item in wallet:
                obj = lookup(item["stock_name"])
                item["price"] = round(obj["price"], 2)

            print(wallet)
            return render_template("sell.html", wallet=wallet)
        else:
            # user dosen´t have a wallet, retur sell html without data
            return render_template("sell.html")
