from app import app, db
from flask import render_template, flash, redirect, url_for, request
from flask_login import current_user, login_user, logout_user, login_required
from werkzeug.urls import url_parse
# from jinja2.environment import Template

from app.models import User, Post
from app.forms import LoginForm, RegistrationForm

from typing import Any, Union, cast, NewType

HTML = NewType('HTML', str)
httpResponse = NewType('httpResponse', object)  # = flask.Response


@app.route('/')
@app.route('/index')
@login_required
def index() -> HTML:
    posts = [
        {
            'author': {'username': 'John'},
            'body': 'Beautiful day in Portland!'
        },
        {
            'author': {'username': 'Susan'},
            'body': 'The Avengers movie was so cool!'
        }
    ]
    rendered: HTML = render_template('index.jinja', title='Home', posts=posts)
    return rendered


@app.route('/login', methods=['GET', 'POST'])
def login() -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        response: httpResponse = redirect(url_for('index'))
        return response
    form = LoginForm()
    if form.validate_on_submit():
        user = User.query.filter_by(username=form.username.data).first()
        if user is None or not user.check_password(form.password.data):
            flash('Invalid username or password')
            response = redirect(url_for('login'))
            return response
        login_user(user, remember=form.remember_me.data)
        next_page = request.args.get('next')
        if not next_page or url_parse(next_page).netloc != '': # check if 'next' is within same domain
            next_page = url_for('index')
        response = redirect(next_page)
        return response
    else:
        rendered: HTML = render_template('login.html', title='Sign In', form=form)
        return rendered


@app.route('/logout')
def logout() -> httpResponse:
    logout_user()
    response: httpResponse = redirect(url_for('index'))
    return response


@app.route('/register', methods=['GET', 'POST'])
def register() -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        response: httpResponse = redirect(url_for('index'))
        return response
    form = RegistrationForm()
    if form.validate_on_submit():
        user = User(username=form.username.data, email=form.email.data)
        user.set_password(form.password.data)
        db.session.add(user)
        db.session.commit()
        flash('Congratulations, you are now a registered user!')
        response = redirect(url_for('login'))
        return response
    else:
        rendered: HTML = render_template('register.html', title='Register', form=form)
        return rendered


@app.route('/user/<username>')
@login_required
def user(username: str) -> HTML:
    user = User.query.filter_by(username=username).first_or_404()
    posts = [
        {'author': user, 'body': 'Test post #1'},
        {'author': user, 'body': 'Test post #2'}
    ]
    rendered: HTML = render_template('user.html', user=user, posts=posts)
    return rendered