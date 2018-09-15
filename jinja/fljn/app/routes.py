from . import app, db
from flask import render_template, flash, redirect, url_for, request
from flask_login import current_user, login_user, logout_user, login_required
from werkzeug.urls import url_parse
from datetime import datetime
# from jinja2.environment import Template
from .models import User, Post
from .forms import LoginForm, RegistrationForm

from typing import Any, Union, cast, NewType

HTML = NewType('HTML', str)
httpResponse = NewType('httpResponse', object)  # = flask.Response


@app.before_request
def before_request() -> None:
    if current_user.is_authenticated:
        current_user.last_seen = datetime.utcnow()
        db.session.commit()


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


from .forms import EditProfileForm


@app.route('/edit_profile', methods=['GET', 'POST'])
@login_required
def edit_profile() -> Union[httpResponse, HTML]:
    form = EditProfileForm(current_user.username)
    if form.validate_on_submit():
        current_user.username = form.username.data
        current_user.about_me = form.about_me.data
        db.session.commit()
        flash('Your changes have been saved.')
        response: httpResponse = redirect(url_for('edit_profile'))
        return response
    elif request.method == 'GET':
        form.username.data = current_user.username
        form.about_me.data = current_user.about_me

    rendered: HTML = render_template('edit_profile.html', title='Edit Profile', form=form)
    return rendered


@app.route('/follow/<username>')
@login_required
def follow(username):
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash('User {} not found.'.format(username))
        return redirect(url_for('index'))
    if user == current_user:
        flash('You cannot follow yourself!')
        return redirect(url_for('user', username=username))
    current_user.follow(user)
    db.session.commit()
    flash('You are following {}!'.format(username))
    return redirect(url_for('user', username=username))


@app.route('/unfollow/<username>')
@login_required
def unfollow(username):
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash('User {} not found.'.format(username))
        return redirect(url_for('index'))
    if user == current_user:
        flash('You cannot unfollow yourself!')
        return redirect(url_for('user', username=username))
    current_user.unfollow(user)
    db.session.commit()
    flash('You are not following {}.'.format(username))
    return redirect(url_for('user', username=username))
