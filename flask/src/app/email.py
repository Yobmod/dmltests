from flask import Flask, current_app
from flask_mail import Message
from threading import Thread

from app import mail

from typing import List, Union
from app.types import HTML


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
    Thread(target=send_async_email, args=(current_app._get_current_object(), msg)).start()
