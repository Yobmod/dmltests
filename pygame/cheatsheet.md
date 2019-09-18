# run.py imports <module>s of interest and runs any functions, sqlite db created
monkeytype run <run.py>  

# create stub (.pyi) file in "./types" folder
monkeytype stub <module> > "types/<module>"

# Apply stub types to module. creates file with annotations in typed-src
# If not type in source error, use return -i (increment)
monkeytype apply <module>
retype -i <module>  


# Pipenv
pipenv install --dev
pipenv sync
pipenv run <file>


# testing. See pytest.ini
pytest

#linting. See pylama.ini(pylama, pycodestyle, mccabe), mypy.ini, setup.cfg(flake8)
pylama
flake8
mypy


#typing
from __future__ import annotations
from typing import Any, Union, NewType, TypeVar, cast, TYPE_CHECKING, ...
from mypy_extentions import TypedDict, NamedTuple
