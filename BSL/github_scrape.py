"""Example app to login to GitHub using the StatefulBrowser class."""

import argparse
import mechanicalsoup
from getpass import getpass

parser = argparse.ArgumentParser(description="Login to GitHub.")
parser.add_argument("username")
args = parser.parse_args()

args.password = getpass("Please enter your GitHub password: ")

browser = mechanicalsoup.StatefulBrowser(
    soup_config={'features': 'lxml'},
    raise_on_404=True,
    user_agent='MyBot/0.1: mysite.example.com/bot_info',
)
# Uncomment for a more verbose output:
# browser.set_verbose(2)

browser.open("https://github.com")
browser.follow_link("login")
browser.select_form('#login form')
browser["login"] = args.username
browser["password"] = args.password
resp = browser.submit_selected()

# Uncomment to launch a web browser on the current page:
# browser.launch_browser()

# verify we are now logged in
page = browser.get_current_page()
messages = page.find("div", class_="flash-messages")
if messages:
    print(messages.text)

assert page.select(".logout-form")
if page.select(".logout-form"):
    print("logged in")
else:
    print("not logged in")

print(page.title.text)

# verify we remain logged in (thanks to cookies) as we browse the rest of
# the site
page3 = browser.open("https://github.com/MechanicalSoup/MechanicalSoup")
assert page3.soup.select(".logout-form")

print("done")


url_video = R"https://sig-learning-hub-prod.s3-eu-west-1.amazonaws.com/znmsjz562hmh/transcoded/before_2.webm?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIFHGSGWQGDS6VDTA%2F20191104%2Feu-west-1%2Fs3%2Faws4_request&X-Amz-Date=20191104T143719Z&X-Amz-Expires=3600&X-Amz-SignedHeaders=host&X-Amz-Signature=874990a7c44c67847e842ba9982bd5007667e9b7fc9a5029f6e200bc539e3f88"

bsl = browser.open(url_video)
print(bsl.content)