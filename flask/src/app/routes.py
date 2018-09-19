from flask import render_template, flash, redirect, url_for, request, g
from flask_login import current_user, login_user, logout_user, login_required
from werkzeug.urls import url_parse
from datetime import datetime
from flask_babel import _, get_locale
from guess_language import guess_language
from flask import jsonify
# from jinja2.environment import Template

from . import app, db
from .models import User, Post
from .forms import LoginForm, RegistrationForm, PostForm, ResetPasswordRequestForm, ResetPasswordForm
from .email import send_password_reset_email
from .translate import translate

from typing import Any, Union, Dict, cast, NewType, Optional as Opt

HTML = NewType('HTML', str)
httpResponse = NewType('httpResponse', object)  # = flask.Response


@app.before_request
def before_request() -> None:
    if current_user.is_authenticated:
        current_user.last_seen = datetime.utcnow()
        db.session.commit()
    g.locale = str(get_locale()) # g 'acts a proxy for a werkzeug local'


@app.route('/', methods=['GET', 'POST'])
@app.route('/index', methods=['GET', 'POST'])
@login_required
def index() -> Union[httpResponse, HTML]:
    form = PostForm()
    if form.validate_on_submit():
        language = guess_language(form.post.data)
        if language == 'UNKNOWN' or len(language) > 5:
            language = ''
        post = Post(body=form.post.data, author=current_user, language=language)
        db.session.add(post)
        db.session.commit()
        flash(_('Your post is now live!'))
        response = redirect(url_for('index'))
        return response
    page = request.args.get('page', 1, type=int)
    posts = current_user.followed_posts().paginate(
        page, app.config['POSTS_PER_PAGE'], False)
    next_url = url_for('index', page=posts.next_num) \
        if posts.has_next else None
    prev_url = url_for('index', page=posts.prev_num) \
        if posts.has_prev else None

    rendered: HTML = render_template('main/index.html', title=_('Home'), form=form, posts=posts.items,
                                     next_url=next_url, prev_url=prev_url)
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
            flash(_('Invalid username or password'))
            response = redirect(url_for('login'))
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
            'login.html', title=_('Sign In'), form=form)
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
        flash(_('Congratulations, you are now a registered user!'))
        response = redirect(url_for('login'))
        return response
    else:
        rendered: HTML = render_template(
            'register.html', title=_('Register'), form=form)
        return rendered


@app.route('/user/<username>')
@login_required
def user(username: str) -> HTML:
    user = User.query.filter_by(username=username).first_or_404()
    page = request.args.get('page', 1, type=int)
    posts = user.posts.order_by(Post.timestamp.desc()
        ).paginate(page, app.config['POSTS_PER_PAGE'], False)
    next_url = url_for('user', username=user.username, page=posts.next_num) \
        if posts.has_next else None
    prev_url = url_for('user', username=user.username, page=posts.prev_num) \
        if posts.has_prev else None
    rendered: HTML = render_template('user.html', user=user, posts=posts.items,
                                                  next_url=next_url, prev_url=prev_url)
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
        flash(_('Your changes have been saved.'))
        response: httpResponse = redirect(url_for('edit_profile'))
        return response
    elif request.method == 'GET':
        form.username.data = current_user.username
        form.about_me.data = current_user.about_me

    rendered: HTML = render_template(
        'edit_profile.html', title=_('Edit Profile'), form=form)
    return rendered


@app.route('/follow/<username>')
@login_required
def follow(username: str) -> httpResponse:
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash(_('User %(username)s not found.', username=username))
        return redirect(url_for('index'))
    elif user == current_user:
        flash(_('You cannot follow yourself!'))
        return redirect(url_for('user', username=username))
    current_user.follow(user)
    db.session.commit()
    flash(_('You are following %(username)s!', username=username))
    return redirect(url_for('user', username=username))


@app.route('/unfollow/<username>')
@login_required
def unfollow(username: str) -> httpResponse:
    user = User.query.filter_by(username=username).first()
    if user is None:
        flash(_('User %(username)s not found.', username=username))
        return redirect(url_for('index'))
    if user == current_user:
        flash(_('You cannot unfollow yourself!'))
        return redirect(url_for('user', username=username))
    current_user.unfollow(user)
    db.session.commit()
    flash(_('You are not following %(username)s.', username=username))
    return redirect(url_for('user', username=username))


@app.route('/explore')
@login_required
def explore() -> HTML:
    page = request.args.get('page', 1, type=int)
    posts = Post.query.order_by(Post.timestamp.desc()
                                ).paginate(page, app.config['POSTS_PER_PAGE'], False)
    next_url = url_for('explore', page=posts.next_num) \
        if posts.has_next else None
    prev_url = url_for('explore', page=posts.prev_num) \
        if posts.has_prev else None
    rendered: HTML = render_template("main/index.html", title=_('Explore'), posts=posts.items,
                               next_url=next_url, prev_url=prev_url)
    return rendered


@app.route('/reset_password_request', methods=['GET', 'POST'])
def reset_password_request() -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        return redirect(url_for('index'))
    form = ResetPasswordRequestForm()
    if form.validate_on_submit():
        user = User.query.filter_by(email=form.email.data).first()
        if user:
            send_password_reset_email(user)
        flash(_('Check your email for the instructions to reset your password'))
        return redirect(url_for('login'))
    return render_template('reset_password_request.html',
                           title=_('Reset Password'), form=form)


@app.route('/reset_password/<token>', methods=['GET', 'POST'])
def reset_password(token: str) -> Union[httpResponse, HTML]:
    if current_user.is_authenticated:
        return redirect(url_for('index'))

    user = cast(Opt[User], User.verify_reset_password_token(token))
    if not user: 
        return redirect(url_for('index'))

    form = ResetPasswordForm()
    if form.validate_on_submit():
        user.set_password(form.password.data)
        db.session.commit()
        flash(_('Your password has been reset.'))
        return redirect(url_for('login'))

    return render_template('reset_password.html', form=form)


@app.route('/translate', methods=['POST'])
@login_required
def translate_text() -> Dict[str, str]:
    return jsonify({'text': translate(request.form['text'],
                                      request.form['source_language'],
                                      request.form['dest_language'])})
