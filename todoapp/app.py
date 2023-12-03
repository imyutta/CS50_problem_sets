# Import necessary modules and libraries:
import os
import sqlite3
import re

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

# Import helper functions from helpers.py
from helpers import apology, login_required

# Import datetime module:
from datetime import datetime

# Configure the Flask application:
app = Flask(__name__)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///todoapp.db")


# Flask after_request callback (executed after each request)
# Insures that responses are not cached:
@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response



@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    """Show goals and tasks"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Get user's goals data from SQL database:
    tasks = db.execute("SELECT * FROM tasks WHERE users_id =? AND completion = 0", users_id)

    # Get tasks categories (distinct list):
    tasks = db.execute("SELECT * FROM tasks WHERE users_id =? AND completion = 0", users_id)

    # Text in the head for the HTML template:
    welcome_message_h1 = "Chart a course toward\n your loftiest goals "
    welcome_message_p = "through step-by-step planning with todo app"


    # Render the HTML template with data to display:
    return render_template("index.html", tasks=tasks, welcome_message_h1 = welcome_message_h1, welcome_message_p = welcome_message_p, current_page="planning")



@app.route("/add_task", methods=["POST"])
@login_required
def add_task():
    """Add a new task"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Extract data from the form (add new task):
    category = request.form.get("category")
    task = request.form.get("task")
    timeframe = request.form.get("timeframe")
    date = request.form.get("date")
    time = request.form.get("time")
    priority = request.form.get("priority")

    # Insert the new task into the database:
    db.execute("INSERT INTO tasks (users_id, category, task, timeframe, date, time, priority) VALUES (?, ?, ?, ?, ?, ?, ?)",
              users_id, category, task, timeframe, date, time, priority)

    # Redirect back to the index page after adding the goal:
    return redirect("/")



@app.route("/update_task_status/<int:task_id>/<int:completion_value>", methods=["POST"])
@login_required
def update_task_status(task_id, completion_value):
    """Update task status"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Change the completion status in the database:
    db.execute("UPDATE tasks SET completion = ? WHERE users_id = ? AND id = ?", completion_value, users_id, task_id)

    # Redirect back to the index page after updating the task status:
    return jsonify({"success": True})



@app.route("/delete_task/<int:task_id>", methods=["DELETE"])
@login_required
def delete_task(task_id):
    """Delete a task"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Delete the task from the database:
    db.execute("DELETE FROM tasks WHERE users_id = ? AND id = ?", users_id, task_id)

    # Redirect back to the index page after deleting the task:
    return jsonify({"success": True})



@app.route("/agenda", methods=["GET", "POST"])
@login_required
def agenda():
    """Daily agenda"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Get user's tasks with specified date and time information (for the appointments html table):
    appointments = db.execute("SELECT id, category, task, completion, date, time FROM tasks WHERE users_id =? AND completion = 0 AND (date IS NOT NULL AND date != '' OR time IS NOT NULL AND time != '')", users_id)

    # Get user's high priority tasks for weekdays-planning  html table:
    weekdays = db.execute("SELECT id, category, task, completion, timeframe FROM tasks WHERE users_id =? AND completion = 0 AND priority = 'High'", users_id)

    # Get user's high priority tasks for weekends-planning  html table:
    weekends = db.execute("SELECT id, category, task, completion, timeframe FROM tasks WHERE users_id =? AND completion = 0 AND priority = 'High'", users_id)

    # Text in the head of the HTML template:
    welcome_message_h1 = " MY TASKS "
    welcome_message_p = "NOTICE: Weekly schedule shows your 'high priority' tasks "

    # Render the HTML template with data to display:
    return render_template("agenda.html", appointments=appointments, weekdays = weekdays, weekends=weekends, welcome_message_h1 = welcome_message_h1, welcome_message_p = welcome_message_p, current_page="agenda")



@app.route("/completed", methods=["GET", "POST"])
@login_required
def completed():
    """Completed tasks"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # Get user's completed tasks data:
    tasks = db.execute("SELECT id, category, task, completion FROM tasks WHERE users_id =? AND completion = 1", users_id)

    # Text in the head for the HTML template:
    welcome_message_h1 = "History "

    # Render the HTML template with data to display:
    return render_template("completed.html", tasks=tasks, welcome_message_h1 = welcome_message_h1, current_page="completed")



@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST):
    if request.method == "POST":

        # Ensure username was submitted:
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted:
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

    # Forget any user_id:
    session.clear()

    # Redirect user to login form:
    return redirect("/")



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



@app.route("/password_change", methods=["GET", "POST"])
def password_change():
    """Password change"""
    # Find what user is currently logged in:
    users_id = session["user_id"]

    # User reached the route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Collect the user's data:
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")

        # Ensure an old password is correct:
        # Query database for the old password hash:
        hash = db.execute("SELECT hash FROM users WHERE id = ?", users_id)

        # Ensure the old password is correct
        if len(hash) != 1 or not check_password_hash(hash[0]["hash"], old_password):
            return apology("invalid password", 400)

        # Ensure a new password was submitted:
        elif len(new_password) == 0:
            return apology("must provide password", 400)

        # Ensure new password and confirmation match:
        elif new_password != confirmation:
            return apology("new password and confirmation do not match")

        # Ensure the password meets complexity requirements:
        elif not re.match(r'^(?=/*[A-Zn-z])(?=.*\d)(?=.*[@$!%*#?&])', new_password):
            return apology("password must contain at least 1 letter, 1 number and 1 symbol", 400)

        # Update database:
        hash = generate_password_hash(new_password)
        db.execute("UPDATE users SET hash = ? WHERE id = ?", hash, users_id)

        # Redirect user to home page:
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("password_change.html")
