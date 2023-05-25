import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

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

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Collect the data:
        # Take a symbol from a user
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide a symbol", 403)

        # Take the number of shares user wants to buy
        number_of_shares = request.form.get("shares")
        # Check if the number of shares provided by the user is digit
        if not number_of_shares.isdigit():
            return apology("a number of shares should be a positive number", 403)

        # Convert the number of shares from string to an integer
        number_of_shares = float(number_of_shares)

        # Look up a stock's current price
        quotes = lookup(symbol)
        # Check if the current stock price has been sucsesfully found
        if not quotes:
            return apology("the symbol does not exist", 403)
        else:
            # Find the amount of money needed to buy the stocks
            share_price = float(quotes["price"])
            total_price = share_price * number_of_shares

        # Remember session user id
        users_id = session["user_id"]

        # Query the database for users cash
        cash = db.execute("SELECT * FROM users WHERE id = ?", users_id)

        # Check if there are enough money in user's cash
        if cash[0]["cash"] < total_price:
            return apology("not enough cash", 403)
        else:
            # Calculate how much cash will user have after purchase
            cash_renewed = cash[0]["cash"] - total_price

            # find users data in the purchase database
            users_purchases = db.execute("SELECT * FROM purchases WHERE id = ?", user_id)
            # If it is a first buy order from this user, insert him to purchases database
            if not users_purchases:
                db.execute("INSERT INTO purchases (id, symbol, price, amount) VALUES ?, ?, ?, ?", user_id, symbol, share_price, number_of_shares)

                db.execute("UPDATE users SET cash TO ? WHERE id = ?", cash_renewed, user_id)
            # If user is already exist in the purchase database, just updte the purchase database
            else:
                # If user has already bought this share in the past - update his data in the purchases database
                if users_purchases[0]["symbol"] == symbol:
                    number_of_shares = int(users_purchases[0]["amount"]) + number_of_shares
                    db.execute("UPDATE purchases SET (price, amount) TO ?, ? WHERE id = ? AND symbol = ?", share_price, number_of_shares, user_id, symbol)

                    # renew users cash data
                    db.execute("UPDATE users SET cash TO ? WHERE id = ?", cash_renewed, user_id)
                    return redirect("/")
                else:
                    # If user is buying this share for the first time, add the data to the purchases database
                    db.execute("INSERT INTO purchases (id, symbol, price, amount) VALUES ?, ?, ?, ?", user_id, symbol, share_price, number_of_shares)
                    db.execute("UPDATE users SET cash TO ? WHERE id = ?", cash_renewed, user_id)

                    # Redirect user to home page
                    return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
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
        # Collect the data:
        quotes = lookup(request.form.get("symbol"))

        # Make sure the symbol exists
        if not quotes:
            return apology("Invalid symbol", 403)

        # If the symbol exists, show user the quote price
        return render_template("quoted.html", quotes=quotes)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Collect the user's data:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        hash = generate_password_hash(password)

        # Ensure username was submitted
        if len(username) == 0:
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif len(password) == 0:
            return apology("must provide password", 403)

        # Ensure passwords match
        elif password != confirmation:
            return apology("passwords do not match", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure username does not exist in the database
        if not rows:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
            new_user_id = db.execute("SELECT id FROM users WHERE username = ?", username)
        else:
            return apology("username already exist", 403)

        # Remember which user has logged in
        session["user_id"] = new_user_id

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
