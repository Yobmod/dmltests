from flask import render_template, flash, redirect, url_for, request, g, current_app, jsonify
from flask_login import login_required, current_user
from datetime import datetime
from flask_babel import _, get_locale
from guess_language import guess_language

from app import db
from app.models import User, Post
from app.translate import translate
from app.main import bp
from app.main.forms import EditProfileForm, PostForm, SearchForm

from app.types import HTML, httpResponse
from typing import Union, cast


@bp.before_request
def before_request() -> None:
    if current_user.is_authenticated:
        current_user.last_seen = datetime.utcnow()
        db.session.commit()
        g.search_form = SearchForm()
    g.locale = str(get_locale())  # g 'acts a proxy for a werkzeug local'


@bp.route('/user/<username>/popup')
@login_required
def user_popup(username: str) -> HTML:
    user = User.query.filter_by(username=username).first_or_404()
    rendered: HTML = render_template('user_popup.html', user=user)
    return rendered


@bp.route('/search')
@login_required
def search() -> Union[httpResponse, HTML]:
    if not g.search_form.validate():
        response: httpResponse = redirect(url_for('main.explore'))
        return response
    else:
        page = request.args.get('page', 1, type=int)
        posts, total = Post.search(g.search_form.q.data, page,
                                   current_app.config['POSTS_PER_PAGE'])
        next_url = url_for('main.search', q=g.search_form.q.data, page=page + 1) \
            if total > page * current_app.config['POSTS_PER_PAGE'] else None
        prev_url = url_for('main.search', q=g.search_form.q.data, page=page - 1) \
            if page > 1 else None
        rendered: HTML = render_template('search.html', title=_('Search'),
                                         posts=posts, next_url=next_url, prev_url=prev_url)
        return rendered


@bp.route('/', methods=['GET', 'POST'])
@bp.route('/index', methods=['GET', 'POST'])
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
        response = cast(httpResponse, redirect(url_for('main.index')))
        return response
    else:
        page = request.args.get('page', 1, type=int)
        posts = current_user.followed_posts().paginate(
            page, current_app.config['POSTS_PER_PAGE'], False)
        next_url = url_for('main.index', page=posts.next_num) \
            if posts.has_next else None
        prev_url = url_for('main.index', page=posts.prev_num) \
            if posts.has_prev else None
        rendered: HTML = render_template('main/index.html', title=_('Home'), form=form,
                                         posts=posts.items, next_url=next_url, prev_url=prev_url)
        return rendered


@bp.route('/user/<username>')
@login_required
def user(username: str) -> HTML:
    user = User.query.filter_by(username=username).first_or_404()
    page = request.args.get('page', 1, type=int)
    posts = user.posts.order_by(Post.timestamp.desc()
                                ).paginate(page, current_app.config['POSTS_PER_PAGE'], False)
    next_url = url_for('main.user', username=user.username, page=posts.next_num) \
        if posts.has_next else None
    prev_url = url_for('main.user', username=user.username, page=posts.prev_num) \
        if posts.has_prev else None
    rendered: HTML = render_template('user.html', user=user, posts=posts.items,
                                     next_url=next_url, prev_url=prev_url)
    return rendered


@bp.route('/edit_profile', methods=['GET', 'POST'])
@login_required
def edit_profile() -> Union[httpResponse, HTML]:
    form = EditProfileForm(current_user.username)
    if form.validate_on_submit():
        current_user.username = form.username.data
        current_user.about_me = form.about_me.data
        db.session.commit()
        flash(_('Your changes have been saved.'))
        response: httpResponse = redirect(url_for('main.edit_profile'))
        return response
    elif request.method == 'GET':
        form.username.data = current_user.username
        form.about_me.data = current_user.about_me

    rendered: HTML = render_template('edit_profile.html', title=_('Edit Profile'), form=form)
    return rendered


@bp.route('/follow/<username>')
@login_required
def follow(username: str) -> httpResponse:
    user = User.query.filter_by(username=username).first()
    response: httpResponse
    if user is None:
        flash(_('User %(username)s not found.', username=username))
        response = redirect(url_for('main.index'))
    elif user == current_user:
        flash(_('You cannot follow yourself!'))
        response = redirect(url_for('main.user', username=username))
    else:
        current_user.follow(user)
        db.session.commit()
        flash(_('You are following %(username)s!', username=username))
        response = redirect(url_for('main.user', username=username))
    return response


@bp.route('/unfollow/<username>')
@login_required
def unfollow(username: str) -> httpResponse:
    user = User.query.filter_by(username=username).first()
    response: httpResponse
    if user is None:
        flash(_('User %(username)s not found.', username=username))
        response = redirect(url_for('main.index'))
    elif user == current_user:
        flash(_('You cannot unfollow yourself!'))
        response = redirect(url_for('main.user', username=username))
    else:
        current_user.unfollow(user)
        db.session.commit()
        flash(_('You are not following %(username)s.', username=username))
        response = redirect(url_for('main.user', username=username))
    return response


@bp.route('/explore')
@login_required
def explore() -> HTML:
    page = request.args.get('page', 1, type=int)
    posts = Post.query.order_by(Post.timestamp.desc()
                                ).paginate(page, current_app.config['POSTS_PER_PAGE'], False)
    next_url = url_for('main.explore', page=posts.next_num) if posts.has_next else None
    prev_url = url_for('main.explore', page=posts.prev_num) if posts.has_prev else None
    rendered: HTML = render_template("main/index.html", title=_('Explore'), posts=posts.items,
                                     next_url=next_url, prev_url=prev_url)
    return rendered


@bp.route('/translate', methods=['POST'])
@login_required
def translate_text() -> httpResponse:
    response: httpResponse = jsonify({'text': translate(request.form['text'],
                                                        request.form['source_language'],
                                                        request.form['dest_language'])})
    return response
