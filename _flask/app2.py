# Greets user

from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index2():
    return render_template("index2.html", name=request.args.get("name", "world"))