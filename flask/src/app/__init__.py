import os
from flask import Flask, request, current_app
from config import Config
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from flask_login import LoginManager
from flask_mail import Mail
from flask_bootstrap import Bootstrap
from flask_moment import Moment
from flask_babel import Babel, lazy_gettext as _l
from elasticsearch import Elasticsearch
import logging
from logging.handlers import SMTPHandler, RotatingFileHandler

from typing import Union, Tuple, Type

db = SQLAlchemy()
migrate = Migrate()
login = LoginManager()
mail = Mail()
bootstrap = Bootstrap()
moment = Moment()
babel = Babel()

login.login_view = 'auth.login'  # name of view
login.login_message = _l('Please log in to access this page.')


def create_app(config_class: Type[Config]=Config) -> Flask:
    app = Flask(__name__)
    app.config.from_object(config_class)

    db.init_app(app)
    migrate.init_app(app, db)
    login.init_app(app)
    mail.init_app(app)
    bootstrap.init_app(app)
    moment.init_app(app)
    babel.init_app(app)

    if app.config['ELASTICSEARCH_URL']:
        app.elasticsearch = Elasticsearch([app.config['ELASTICSEARCH_URL']])
    else:
        app.elasticsearch = None

    from app.auth import bp as auth_bp
    from app.main import bp as main_bp
    from app.errors import bp as errors_bp

    app.register_blueprint(main_bp, url_prefix='/')
    app.register_blueprint(auth_bp, url_prefix='/auth')
    app.register_blueprint(errors_bp)
    print('blueprints loaded')

    if not app.debug and not app.testing:
        if current_app.config['MAIL_SERVER']:
            auth = None
            if current_app.config['MAIL_USERNAME'] or current_app.config['MAIL_PASSWORD']:
                auth = (current_app.config['MAIL_USERNAME'], current_app.config['MAIL_PASSWORD'])
            if current_app.config['MAIL_USE_TLS']:
                secure: Union[None, Tuple[str], Tuple[str, str]] = ('', )
            else:
                secure = None

            mail_handler = SMTPHandler(
                mailhost=(current_app.config['MAIL_SERVER'], current_app.config['MAIL_PORT']),
                fromaddr=current_app.config['ADMINS'][0],
                toaddrs=current_app.config['ADMINS'], subject='Microblog Failure',
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

    return app


@babel.localeselector
def get_locale() -> str:
    lang: str = request.accept_languages.best_match(current_app.config['LANGUAGES'])
    # lang = 'es'
    return lang
# Commands to generate .po files:
# pybabel extract -F babel.cfg -k _l -o messages.pot . ## create .pot file
# pybabel init -i messages.pot -d app/translations -l es  ## create .po files
# pybabel compile - d app/translations  # compile to .mo files (after trans added to .po)
# pybabel update - i messages.pot - d app/translations  # remake .pot file first, then this updates .po


from app import models


