from flask import render_template
from . import app, db

from .routes import HTML
from typing import Tuple

@app.errorhandler(404)
def not_found_error(error: Exception) -> Tuple[HTML, int]:
    rendered: HTML = render_template('404.html')
    return (rendered, 404)


@app.errorhandler(500)
def internal_error(error: Exception) -> Tuple[HTML, int]:
    db.session.rollback()
    rendered: HTML = render_template('500.html')
    return rendered, 500
