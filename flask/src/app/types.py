from typing import Any, List, Union, Dict, cast, NewType, Optional as Opt, TypeVar  # noqa: F401
from flask import Response
from sqlalchemy.orm import Session

HTML = NewType('HTML', str)
URL = NewType('URL', str)


class httpResponse(Response):
    """Subclass of flask.Response for type hinting"""
    pass


class SearchSession(Session):
    """Subclass of sqlalchemy.Session for type hinting"""
    _changes: Dict[str, List[Any]] = {'add': [], 'update': [], 'delete': []}
