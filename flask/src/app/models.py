from datetime import datetime
from werkzeug.security import generate_password_hash, check_password_hash
from flask_login import UserMixin
from hashlib import md5
from time import time
import jwt

from . import db, app
from . import login

from typing import List, Optional as Opt, TypeVar

UserType = TypeVar('UserType', bound='User')
PostType = TypeVar('PostType', bound='Post')


@login.user_loader
def load_user(id: str) -> UserType:
    user_from_id: UserType = User.query.get(int(id))
    return user_from_id


followers = db.Table('followers',
                     db.Column('follower_id', db.Integer,
                               db.ForeignKey('user.id')),
                     db.Column('followed_id', db.Integer,
                               db.ForeignKey('user.id'))
                     )


class User(UserMixin, db.Model):        # type: ignore
    __tablename__ = 'user'

    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64), index=True, unique=True)
    email = db.Column(db.String(120), index=True, unique=True)
    password_hash = db.Column(db.String(128))
    posts = db.relationship('Post', backref='author', lazy='dynamic')
    about_me = db.Column(db.String(140))
    last_seen = db.Column(db.DateTime, default=datetime.utcnow)
    followed = db.relationship('User',
                               secondary=followers,
                               primaryjoin=(followers.c.follower_id == id),
                               secondaryjoin=(followers.c.followed_id == id),
                               backref=db.backref('followers', lazy='dynamic'),
                               lazy='dynamic')

    def __repr__(self) -> str:
        return '<User {}>'.format(self.username)

    def avatar(self, size: int) -> str:
        digest = md5(self.email.lower().encode('utf-8')).hexdigest()
        return 'https://www.gravatar.com/avatar/{}?d=identicon&s={}'.format(digest, size)

    def set_password(self, password: str) -> None:
        self.password_hash = generate_password_hash(password)

    def check_password(self, password: str) -> bool:
        password_hash_match: bool = check_password_hash(
            self.password_hash, password)
        return password_hash_match

    def follow(self, user: UserType) -> None:
        if not self.is_following(user):
            self.followed.append(user)

    def unfollow(self, user: UserType) -> None:
        if self.is_following(user):
            self.followed.remove(user)

    def is_following(self, user: UserType) -> bool:
        is_follow: bool = (self.followed.filter(
            followers.c.followed_id == user.id).count() > 0)
        return is_follow

    def followed_posts(self) -> List[PostType]:
        followed = Post.query.join(followers,
                                   (followers.c.followed_id == Post.user_id)).filter(
            followers.c.follower_id == self.id)
        own = Post.query.filter_by(user_id=self.id)
        my_follow_posts: List[Post] = followed.union(
            own).order_by(Post.timestamp.desc())
        return my_follow_posts

    def get_reset_password_token(self, expires_in: int = 600) -> str:
        return jwt.encode(
            {'reset_password': self.id, 'exp': time() + expires_in},
            app.config['SECRET_KEY'], algorithm='HS256').decode('utf-8')

    @staticmethod
    def verify_reset_password_token(token: str) -> Opt[UserType]:
        try:
            id = jwt.decode(token, app.config['SECRET_KEY'], 
                            algorithms=['HS256'])['reset_password']
        except Exception as e:
            # logger(ERROR)
            return None
        else:
            verified_user: UserType = User.query.get(id)
            return verified_user


class Post(db.Model):       # type: ignore
    __tablename__ = 'post'

    id = db.Column(db.Integer, primary_key=True)
    body = db.Column(db.String(140))
    timestamp = db.Column(db.DateTime, index=True, default=datetime.utcnow)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'))
    language = db.Column(db.String(5))

    def __repr__(self) -> str:
        return '<Post {}>'.format(self.body)
