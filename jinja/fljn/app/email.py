from flask import Flask
from flask import render_template
from flask_mail import Message
from threading import Thread

from . import mail, app
from .models import User

from typing import List, Union, NewType
HTML = NewType('HTML', str)


def send_async_email(app: Flask, msg: Message) -> None:
    with app.app_context():
        mail.send(msg)


def send_email(subject: str,
               sender: str, 
               recipients: List[str], 
               text_body: Union[str, HTML], 
               html_body: HTML) -> None:
    """ # cc bcc field also possible"""
    msg = Message(subject, sender=sender, recipients=recipients)
    msg.body = text_body
    msg.html = html_body
    # mail.send(msg)
    Thread(target=send_async_email, args=(app, msg)).start()


def send_password_reset_email(user: User) -> None:
    token = user.get_reset_password_token()
    send_email('[Microblog] Reset Your Password',
               sender=app.config['ADMINS'][0],
               recipients=[user.email],
               text_body=render_template('email/reset_password.txt',
                                         user=user, token=token),
               html_body=render_template('email/reset_password.html',
                                         user=user, token=token))
