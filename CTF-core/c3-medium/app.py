from flask import Flask, request, make_response, render_template

app = Flask(__name__)

FLAG = "FLAG{COOKIE_SYSTEM_COMPROMISED}"


@app.route("/")
def index():
    # Get the role cookie, default to "guest"
    role = request.cookies.get("role", "guest")
    # Render the homepage with the current role displayed
    resp = make_response(render_template("index.html", role=role))
    # If the cookie is not set, set it to "guest"
    if not request.cookies.get("role"):
        resp.set_cookie("role", "guest")
    return resp


@app.route("/admin")
def admin():
    role = request.cookies.get("role", "guest")
    # Only allow access if role is set to admin
    if role.lower() == "admin":
        return render_template("admin.html", flag=FLAG)
    else:
        return render_template("access_denied.html"), 403


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000)
    print(app.url_map)
