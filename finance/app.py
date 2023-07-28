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
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Get user's stocks, user's numbers of shares:
    users_stocks = db.execute("SELECT symbol, SUM(amount) as total_amount FROM purchases WHERE users_id = ? GROUP BY symbol HAVING amount > 0", users_id)
    # Get user's cash:
    users_cash = db.execute("SELECT cash FROM users WHERE id = ?", users_id)[0]["cash"]

    # Variables
    total_value = users_cash

    # Create a table by iterating over stocks
    for stock in users_stocks:
        quote = lookup(stock["symbol"])
        stock["name"] = quote["name"]
        stock["price"] = quote["price"]
        stock["total"] = stock["price"] * stock["total_amount"]
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
            return apology("must provide a symbol", 403)

        # Take the number of shares user wants to buy:
        number_of_shares = request.form.get("shares")
        # Check if the number of shares provided by the user is digit:
        if not number_of_shares.isdigit():
            return apology("a number of shares should be a positive number", 403)

        # Convert the number of shares from string to an integer:
        number_of_shares = int(number_of_shares)

        # Look up the stock's current price:
        quotes = lookup(symbol)
        # Check if the current stock price has been sucsessfully found:
        if not quotes:
            return apology("the symbol does not exist", 403)
        else:
            # Find the amount of money needed to buy the stocks:
            share_price = quotes["price"]
            total_price = share_price * number_of_shares

        # Remember the session id
        users_id = session["user_id"]

        # Query the database for users money:
        users_cash = db.execute("SELECT * FROM users WHERE id = ?", users_id)

        # Check if there are enough money user has:
        if users_cash[0]["cash"] < total_price:
            return apology("not enough cash", 403)
        else:
            # Calculate how much cash will user have after purchase:
            cash_after_purchase = users_cash[0]["cash"] - total_price

            # Insert the purchase data into the purchases database
            db.execute("INSERT INTO purchases (users_id, symbol, price, amount) VALUES (?, ?, ?, ?)", users_id, symbol, share_price, number_of_shares)
            # Update users database, renew cash amount
            db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_after_purchase, users_id)

            # Redirect user to home page
            return redirect("/")

    # User reached the route via GET (as by clicking a link or via redirect)
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
    # User reached the route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Collect the data:
        quotes = lookup(request.form.get("symbol"))

        # Make sure the symbol exists:
        if not quotes:
            return apology("Invalid symbol", 403)

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
            return apology("must provide username", 403)

        # Ensure a password was submitted:
        elif len(password) == 0:
            return apology("must provide password", 403)

        # Ensure passwords match:
        elif password != confirmation:
            return apology("passwords do not match")

        # Query database for username:
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Ensure that username does not exist in the database:
        if not rows:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
            new_user_id = db.execute("SELECT * FROM users WHERE username = ?", username)
        else:
            return apology("username already exists", 403)

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
            return apology("must provide a symbol", 403)

        # Check if (somehow, once submitted) the user does not own any shares of that stock:
        # Query the database for users purchases with this symbol:
        symbol_lower = symbol.lower()
        users_total_share = db.execute("SELECT SUM(amount) FROM purchases WHERE users_id = ? AND symbol = ?", users_id, symbol_lower)[0]["SUM(amount)"]
        if users__total_share < 1:
            return apology("you do not own any shares of that stock", 403)

        # Take the number of shares user wants to sell:
        number_of_shares = request.form.get("shares")
        # Check if the number of shares provided by the user is digit:
        if not number_of_shares.isdigit():
            return apology ("a number of shares should be a positive number", 403)

        # Convert the number of shares from string to an integer:
        number_of_shares = int(number_of_shares)

        # Check if the number of shares provided by the user is a positive integer:
        if  number_of_shares < 1:
            return apology ("a number of shares should be a positive number", 403)
        elif users_total_share < number_of_shares:
            return apology ("you do not own this many shares of this stock", 403)

        # SELL THE STOCK
        # Check the current stock price:
        share_price = lookup(symbol)["price"]
        # Query the database for users money:
        users_cash = db.execute("SELECT * FROM users WHERE id = ?", users_id)[0]["cash"]
        # Calculate how much cash will user have after the purchase:
        cash_after_purchase = users_cash + (share_price * number_of_shares)
        # Calculate how much stocks user has now:
        users_share_after = users_share - number_of_shares
        # Update databases:
        # Update the purchase database
        db.execute("UPDATE purchases SET amount = ? WHERE users_id = ? AND symbol = ?", users_share_after, users_id, symbol_lower)
        # Update users database, renew cash amount
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_after_purchase, users_id)


        # Redirect user to home page
        return redirect("/")

    # User reached the route via GET (as by clicking a link or via redirect)
    else:
        return render_template("sell.html")


