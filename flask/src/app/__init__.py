import os
from flask import Flask, request, Request
from config import Config
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from flask_login import LoginManager
from flask_mail import Mail
from flask_bootstrap import Bootstrap
from flask_moment import Moment
from flask_babel import Babel, lazy_gettext as _l

import logging
from logging.handlers import SMTPHandler, RotatingFileHandler

from typing import Union, Tuple

app = Flask(__name__)
app.config.from_object(Config)

db = SQLAlchemy(app)
migrate = Migrate(app, db)
login = LoginManager(app)
mail = Mail(app)
bootstrap = Bootstrap(app)
moment = Moment(app)
babel = Babel(app)


@babel.localeselector
def get_locale() -> Request:
    # return 'es'
    return request.accept_languages.best_match(app.config['LANGUAGES'])


#Commands to generate .po files:
# pybabel extract -F babel.cfg -k _l -o messages.pot . ## create .pot file
# pybabel init -i messages.pot -d app/translations -l es  ## create .po files
# pybabel compile - d app/translations  # compile to .mo files (after trans added to .po)
# pybabel update - i messages.pot - d app/translations  # remake .pot file first, then this updates .po

login.login_view = 'login'  # name of view
login.login_message = _l('Please log in to access this page.')



from app import routes, models, errors, email

# app.debug = app.config['FLASK_DEBUG']

if not app.debug:
    if app.config['MAIL_SERVER']:
        auth = None
        if app.config['MAIL_USERNAME'] or app.config['MAIL_PASSWORD']:
            auth = (app.config['MAIL_USERNAME'], app.config['MAIL_PASSWORD'])
        if app.config['MAIL_USE_TLS']:
            secure: Union[None, Tuple[str], Tuple[str, str]] = ('', )
        else:
            secure = None

        mail_handler = SMTPHandler(
            mailhost=(app.config['MAIL_SERVER'], app.config['MAIL_PORT']),
            fromaddr=app.config['ADMINS'][0],
            toaddrs=app.config['ADMINS'], subject='Microblog Failure',
            credentials=auth, secure=secure)
        mail_handler.setLevel(logging.INFO)
        app.logger.addHandler(mail_handler)

    if not os.path.exists('logs'):
        os.mkdir('logs')
    file_handler = RotatingFileHandler('logs/microblog.log', maxBytes=10240,
                                       backupCount=10)
    file_handler.setFormatter(logging.Formatter(
        '%(asctime)s %(levelname)s: %(message)s [in %(pathname)s:%(lineno)d]'))
    file_handler.setLevel(logging.INFO)
    app.logger.addHandler(file_handler)

    app.logger.setLevel(logging.INFO)
    app.logger.info('Microblog startup')
