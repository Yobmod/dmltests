from flask_mail import Message
from . import mail

from typing import List

def send_email(subject: str,
               sender: str, 
               recipients: List[str], 
               text_body: str, 
               html_body: str) -> None:
    """ # cc bcc field also possible"""
    msg = Message(subject, sender=sender, recipients=recipients)
    msg.body = text_body
    msg.html = html_body
    mail.send(msg)
