from bottle import route, run, template  # type: ignore
from typing import Any


@route('/hello/<name>')
def index(name: str) -> str:
	return template('<b>Hello {{name}}</b>!', name=name)


run(host='localhost', port=8080)
