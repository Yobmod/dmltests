from .webui import APP
# from .mytypes import HTML, httpResponse, jsonResponse


@APP.route('/')
def index() -> str:
    # rendered: HTML = render_template('user_popup.html', user=user)
    return "it works"

