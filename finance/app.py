import os
import sqlite3
import re

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime

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
        print("test")
        """Show portfolio of stocks"""
        # Find what user is currently logged in:
        users_id = session["user_id"]

        # Get user's stocks, user's numbers of shares:
        users_stocks = db.execute("SELECT symbol, amount FROM users_stocks WHERE users_id = ? GROUP BY symbol HAVING amount > 0", users_id)
        # Get user's cash:
        users_cash = db.execute("SELECT cash FROM users WHERE id = ?", users_id)[0]["cash"]

        # Variables
        total_value = users_cash

        # Create a table by iterating over stocks
        for stock in users_stocks:
            quote = lookup(stock["symbol"])
            stock["name"] = quote["name"]
            stock["price"] = quote["price"]
            stock["total"] = stock["price"] * stock["amount"]
            total_value += stock["total"]

        formatted_users_cash =round(users_cash, 2)
        formatted_total_value=round(total_value, 2)
        return render_template("index.html", users_stocks=users_stocks, users_cash=formatted_users_cash, total_value=formatted_total_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # User reached route via post (as by submitting a form via POST)
    if request.method == "POST":
        # Collect the data:
        # Take a symbol from the user
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide a symbol", 400)

        # Remember the session id
        users_id = session["user_id"]

        # Prepare symbol
        symbol = symbol.upper()

        # Look up the stock's current price:
        quotes = lookup(symbol)

        # Check if the current stock price has been sucsessfully found:
        if not quotes:
            return apology("the symbol does not exist", 400)

        # Get the number of shares user wants to buy:
        number_of_shares = request.form.get("shares")

        if not number_of_shares or not number_of_shares.isdigit():
            return apology("a number of shares should be a positive number", 400)

        # Convert the number of shares from string to an integer:
        number_of_shares = int(number_of_shares)

        # Find the amount of money needed to buy the stocks:
        share_price = quotes["price"]
        total_price = share_price * number_of_shares



        # Query the database for users money:
        users_cash = db.execute("SELECT * FROM users WHERE id = ?", users_id)

        # Check if there are enough money user has:
        if users_cash[0]["cash"] < total_price:
            return apology("not enough cash", 400)
        else:
            # Calculate how much cash will user have after purchase:
            cash_after_purchase = users_cash[0]["cash"] - total_price

            # Get the current date and time:
            transactions_datetime = datetime.now()
            # Insert the purchase data into the purchases database:
            db.execute("INSERT INTO purchases (users_id, symbol, price, amount, transactions_datetime) VALUES (?, ?, ?, ?, ?)", users_id, symbol, share_price, number_of_shares, transactions_datetime)
            # Update users database, renew cash amount:
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_after_purchase, users_id)

            # Update users_stocks database:
            # Check if the users_stocks database already has data about this stock:
            existing_stock = db.execute("SELECT * FROM users_stocks WHERE users_id = ? AND symbol = ?", users_id, symbol)
            if existing_stock:
                # If existing stock already exists, update the amount by adding number_of_shares to the existing amount:
                updated_amount = existing_stock[0]["amount"] + number_of_shares
                db.execute("UPDATE users_stocks SET amount = ? WHERE users_id = ? AND symbol = ?", updated_amount, users_id, symbol)
            else:
                # If the stock does not exist, insert a new row into users_stocks database:
                db.execute("INSERT INTO users_stocks (users_id, symbol, amount) VALUES (?, ?, ?)", users_id, symbol, number_of_shares)
            # Redirect user to home page
            return redirect("/")

    # User reached the route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Get user's stocks, user's numbers of shares:
    users_stocks = db.execute("SELECT symbol, amount, price, transactions_datetime FROM purchases WHERE users_id = ?", users_id)

    return render_template("history.html", users_stocks=users_stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

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
    # User reached the route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Collect the data:
        quotes = lookup(request.form.get("symbol"))

        # Make sure the symbol exists:
        if not quotes:
            return apology("Invalid symbol", 400)

        print("quOTES", quotes)
        # If the symbol exists, show user the quote price:
        return render_template("quoted.html", quotes=quotes)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached the route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Collect the user's data:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        hash = generate_password_hash(password)

        # Ensure a username was submitted:
        if len(username) == 0:
            return apology("must provide username", 400)

        # Ensure a password was submitted:
        elif len(password) == 0:
            return apology("must provide password", 400)

        # Ensure passwords match:
        elif password != confirmation:
            return apology("passwords do not match")

        # Ensure the password meets complexity requirements:
        elif not re.match(r'^(?=/*[A-Zn-z])(?=.*\d)(?=.*[@$!%*#?&])', password):
            return apology("password must contain at least 1 letter, 1 number and 1 symbol", 400)

        # Query database for username:
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure that username does not exist in the database:
        if not rows:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
            new_user_id = db.execute("SELECT * FROM users WHERE username = ?", username)
        else:
            return apology("username already exists", 400)

        # Remember which user has just logged in:
        session["user_id"] = new_user_id[0]["id"]

        # Redirect user to home page:
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Require that a user input a stock’s symbol, implemented as a select menu whose name is symbol.
    # User reached route via post (as by submitting a form via POST)
    if request.method == "POST":
        # Collect the data:
        # Take a symbol from the user
        symbol = request.form.get("symbol")

        # Render an apology if the user fails to select a stock
        if not symbol:
            return apology("must provide a symbol", 400)
        # Prepare symbol
        symbol = symbol.upper()

        # Check if (somehow, once submitted) the user does not own any shares of that stock:
        # Query the database for users purchases with this symbol:
        users_total_share = db.execute("SELECT SUM(amount) AS total_amount FROM users_stocks WHERE users_id = ? AND symbol = ?", users_id, symbol)[0]["total_amount"]
        if users_total_share < 1:
            return apology("you do not own any shares of that stock", 400)

        # Take the number of shares user wants to sell:
        number_of_shares = request.form.get("shares")

        # Check if the number of shares provided by the user is digit:
        if not number_of_shares.isdigit():
            return apology ("a number of shares should be a positive number", 400)

        # Convert the number of shares from string to an integer:
        number_of_shares = int(number_of_shares)

        # Check if the number of shares provided by the user is a positive integer:
        if  number_of_shares < 1:
            return apology ("a number of shares should be a positive number", 400)
        elif users_total_share < number_of_shares:
            return apology ("you do not own this many shares of this stock", 400)

        # SELL THE STOCK
        # Check the current stock price:
        share_price = lookup(symbol)["price"]

        # Query the database for users money:
        users_cash = db.execute("SELECT * FROM users WHERE id = ?", users_id)[0]["cash"]
        # Calculate how much cash will user have after the purchase:
        cash_after_purchase = users_cash + (share_price * number_of_shares)
        # Quiry purchases database for a single users_share
        users_share_before = db.execute("SELECT amount FROM users_stocks WHERE users_id = ? AND symbol = ?", users_id, symbol)[0]["amount"]

        # Calculate how much stocks user has now:
        users_share_after = users_share_before - number_of_shares

        # Update databases:
        # Get the current date and time:
        transactions_datetime = datetime.now()
        # Check if cash_after_purchase is zero
        if users_share_after == 0:
            # Delete the row from users_stocks
            db.execute("DELETE FROM users_stocks WHERE users_id = ? AND symbol = ?", users_id, symbol)
        else:
            # Update the purchase database
            db.execute("UPDATE users_stocks SET amount = ? WHERE users_id = ? AND symbol = ?", users_share_after, users_id, symbol)

        # Update users database, renew cash amount
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_after_purchase, users_id)
        # Insert the data into the purchases database:
        db.execute("INSERT INTO purchases (users_id, symbol, price, amount, transactions_datetime) VALUES (?, ?, ?, ?, ?)", users_id, symbol, share_price, -number_of_shares, transactions_datetime)

        # Redirect user to home page
        return redirect("/")

    # User reached the route via GET (as by clicking a link or via redirect)
    else:
        symbols = db.execute("SELECT DISTINCT symbol FROM users_stocks WHERE users_id = ?", users_id)
        symbols_list = [row["symbol"] for row in symbols]
        return render_template("sell.html", symbols=symbols_list)


@app.route("/cash", methods=["GET", "POST"])
@login_required
def cash():
    """Add cash"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Require that user input amount of cash he wants to add:
    # User reached route via post (as by submitting a form via POST)
    if request.method == "POST":
        # Collect the data:
        # Take a symbol from the user
        amount = request.form.get("amount")

        # Ensure user submitted amount number:
        if not amount or not amount.isdigit():
            return apology("amount of cash should be a positive integer", 400)

        # Convert the amount of cash from a string to an integer:
        amount = int(amount)

        # UPDATE DATABASE
        # Ensure the amount is a positive integer:
        # Query the database for users money:
        users_cash = db.execute("SELECT * FROM users WHERE id = ?", users_id)[0]["cash"]

        # Find the updated users_cash:
        users_cash = users_cash + amount

        # Update users database, renew cash amount:
        db.execute("UPDATE users SET cash = ? WHERE id = ?", users_cash, users_id)

        # Redirect user to home page
        return redirect("/")

    # User reached the route via GET (as by clicking a link or via redirect)
    else:
        return render_template("cash.html")




@app.route("/register", methods=["GET", "POST"])
def password_change():
    """Password change"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # User reached the route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Collect the user's data:
        username = request.form.get("username")
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")
        hash = generate_password_hash(new_password)

        # Ensure a username was submitted:
        if len(username) == 0:
            return apology("must provide username", 400)

        # Ensure a password was submitted:
        elif len(password) == 0:
            return apology("must provide password", 400)

        # Ensure passwords match:
        elif password != confirmation:
            return apology("passwords do not match")

        # Ensure the password meets complexity requirements:
        elif not re.match(r'^(?=/*[A-Zn-z])(?=.*\d)(?=.*[@$!%*#?&])', password):
            return apology("password must contain at least 1 letter, 1 number and 1 symbol", 400)

        # Query database for username:
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure that username does not exist in the database:
        if not rows:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
            new_user_id = db.execute("SELECT * FROM users WHERE username = ?", username)
        else:
            return apology("username already exists", 400)

        # Remember which user has just logged in:
        session["user_id"] = new_user_id[0]["id"]

        # Redirect user to home page:
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")

