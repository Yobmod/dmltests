import subprocess
import json

from pathlib import Path
from git import Repo, exc
import dotenv
import os
from datetime import datetime

from git.diff import _octal_repl
# import safety

"""
poetry config virtualenvs.in-project true
"""

# TODO: get username and pw using dotenv
# use typer or argparse to get commit msg. if blank, use date + id?
# Do a check with "safety" lib. use subprocess?
# add progressbar from git lib?

cwd = Path.cwd().resolve()
try:
    git_wd = cwd
    repo = Repo(git_wd)
except exc.InvalidGitRepositoryError:
    git_wd = cwd.parent
    repo = Repo(git_wd)
assert not repo.bare
print(type(repo.working_tree_dir))
print(type(git_wd.resolve()))
assert repo.working_tree_dir == str(git_wd.resolve())

dotenv.load_dotenv(cwd / ".env")
username = os.getenv("GIT_USERNAME") or "DML"
password = os.getenv("GIT_PASSWORD")  # or None

repo.remotes.origin.pull()

if repo.is_dirty():
    changedFiles = [item.a_path for item in repo.index.diff(None)]
    repo.git.add(update=True)
    print(f"Modifying files: {changedFiles}")
    # TODO get list of changed files. repo.diff? repo.git.diff?
    if repo.untracked_files:
        print(f"Adding files: {repo.untracked_files}")  # list of filename strings that have not been added
        repo.index.add(repo.untracked_files)
    update_pending = True
else:
    update_pending = False


commit_msg = ""


if update_pending:
    if not commit_msg:
        commit_msg = f"{username}, {datetime.now()}"
    try:
        repo.index.commit(commit_msg)
        print(f"Commiting changes with msg: {commit_msg}")
        repo.remotes.origin.push()
        print(f"Pushing changes to: {repo.remotes.origin.url}")
    except Exception:
        raise


"""
venv_path_bytes = subprocess.check_output("poetry env info --path".split(), shell=True)
venv_path = venv_path_bytes.decode("UTF-8")

Path(".vscode").mkdir(parents=True, exist_ok=True)
Path(".vscode/settings.json").touch()

with open(".vscode/settings.json", "r") as f:
    settings = json.load(f)
    settings["python.pythonPath"] = venv_path

with open(".vscode/settings.json", "w") as f:
    json.dump(settings, f, sort_keys=True, indent=4)


# print(json.dumps(settings, sort_keys=True, indent=4))
"""


def _intp(mode: int, hex: str, st: int, path: str) -> str:
    return "(%o, %s, %i, %s)" % (mode, hex, st, path)

print(_intp(1, "es", 2, "Fr"))

def fintp(mode: int, hex: str, st: int, path: str) -> str:
    assert isinstance(mode, _octal_repl)
    return f"({mode: o}, {hex}, {st}, {path})"

print(fintp(1, "es", 2, "Fr"))