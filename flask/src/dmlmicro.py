from app import create_app, db, cli
from app.models import User, Post, Notification, Message
from config import Config

app = create_app(Config)
cli.register(app)


@app.shell_context_processor
def make_shell_context() -> dict:
    return {'db': db,
            'User': User,
            'Post': Post,
            'Message': Message,
            'Notification': Notification,
            }


print("App running...")
