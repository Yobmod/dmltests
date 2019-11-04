from bs4 import BeautifulSoup as bs
from requests import Response
import mechanicalsoup as ms

# from typing import TYPE_CHECKING

browser: ms.StatefulBrowser = ms.StatefulBrowser(soup_config={'features': 'lxml'})

response: Response = browser.open("http://httpbin.org/")
print(response)

soup: bs = browser.get_current_page()
print(soup)
soup.find_all('legend')

form = browser.get_current_form()
if form:
    form.print_summary()

try:
    form = browser.select_form('form[action="/post"]')
except ms.utils.LinkNotFoundError:
    print("Link not found")

"""The argument to select_form() is a CSS selector. Here, we select an HTML tag named form having an attribute action whose value 
is "/post". Since there’s only one form in the page, browser.select_form() would have done the trick too.
Now, give a value to fields in the form. First, what are the available fields? You can print a summary of the currently selected 
form with print_summary():"""

if form:
    browser["custname"] = "Me"
    browser["custtel"] = "00 00 0001"
    browser["custemail"] = "nobody@example.com"
    browser["comments"] = "This pizza looks really good :-)"

    response = browser.submit_selected()
    print(response)
