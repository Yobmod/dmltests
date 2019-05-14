from bottle import route, run, template
from typing import NewType

HTMLType = NewType('HTMLType', str)


@route('/hello/<name>')
def index(name: str) -> HTMLType:
    HTML: HTMLType = template('<b>Hello {{name}}</b>!', name=name)
    return HTML


run(host='localhost', port=8080)
