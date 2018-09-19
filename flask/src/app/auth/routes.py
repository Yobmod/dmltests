from flask import render_template, flash, redirect, url_for, request
from flask_login import current_user, login_user, logout_user
from werkzeug.urls import url_parse
from flask_babel import _

from app import db
from app.models import User
from app.auth import bp
from app.auth.forms import LoginForm, RegistrationForm, ResetPasswordRequestForm, ResetPasswordForm
from app.auth.email import send_password_reset_email


from typing import Union, cast, NewType, Optional as Opt

HTML = NewType('HTML', str)
httpResponse = NewType('httpResponse', object)  # = flask.Response


@bp.route('/login', methods=['GET', 'POST'])
def login() -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        response: httpResponse = redirect(url_for('main.index'))
        return response
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.filter_by(username=form.username.data).first()
        if user is None or not user.check_password(form.password.data):
            flash(_('Invalid username or password'))
            response = redirect(url_for('auth.login'))
            return response
        login_user(user, remember=form.remember_me.data)
        next_page = request.args.get('next')
        # check if 'next' is within same domain
        if not next_page or url_parse(next_page).netloc != '':
            next_page = url_for('index')
        response = redirect(next_page)
        return response
    else:
        rendered: HTML = render_template(
            'auth/login.html', title=_('Sign In'), form=form)
        return rendered


@bp.route('/logout')
def logout() -> httpResponse:
    logout_user()
    response: httpResponse = redirect(url_for('main.index'))
    return response


@bp.route('/register', methods=['GET', 'POST'])
def register() -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        response: httpResponse = redirect(url_for('main.index'))
        return response
    form = RegistrationForm()
    if form.validate_on_submit():
        user = User(username=form.username.data, email=form.email.data)
        user.set_password(form.password.data)
        db.session.add(user)
        db.session.commit()
        flash(_('Congratulations, you are now a registered user!'))
        response = redirect(url_for('auth.login'))
        return response
    else:
        rendered: HTML = render_template(
            'auth/register.html', title=_('Register'), form=form)
        return rendered


@bp.route('/reset_password_request', methods=['GET', 'POST'])
def reset_password_request() -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        return redirect(url_for('main.index'))
    form = ResetPasswordRequestForm()
    if form.validate_on_submit():
        user = User.query.filter_by(email=form.email.data).first()
        if user:
            send_password_reset_email(user)
        flash(_('Check your email for the instructions to reset your password'))
        return redirect(url_for('auth.login'))
    return render_template('auth/reset_password_request.html',
                           title=_('Reset Password'), form=form)


@bp.route('/reset_password/<token>', methods=['GET', 'POST'])
def reset_password(token: str) -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        return redirect(url_for('main.index'))

    user = cast(Opt[User], User.verify_reset_password_token(token))
    if not user:
        return redirect(url_for('main.index'))

    form = ResetPasswordForm()
    if form.validate_on_submit():
        user.set_password(form.password.data)
        db.session.commit()
        flash(_('Your password has been reset.'))
        return redirect(url_for('auth.login'))

    return render_template('auth/reset_password.html', form=form)
