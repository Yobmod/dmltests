import os
import dotenv
import argparse
from getpass import getpass

from bs4 import BeautifulSoup as bs
import requests
import mechanicalsoup as ms

# from typing import TYPE_CHECKING

url_parent = "https://www.signaturelearninghub.co.uk/"
url_login = "https://login.signature.org.uk/users/sign_in"
url_login_success = "https://www.signaturelearninghub.co.uk/support"
url_homework = "https://www.signaturelearninghub.co.uk/studies/4"
url_dict = R"https://www.signaturelearninghub.co.uk/studies/4/dictionary?page=1&q[all]=true"
url_video = os.environ['url_video']

# load env and try to get username and password

dotenv.load_dotenv(R".\bsl.env")
login_email = os.environ['username'] or None
login_password = os.environ['password'] or None

parser = argparse.ArgumentParser(description="Login to Signiture.")
parser.add_argument("username")
args = parser.parse_args()
args.password = getpass("Please enter your Signiture password: ")

if login_email is None:
    login_email = args.username
    login_email = "yobmod@gmail.com"  # TODO: put this in env

if login_password is None:
    login_password = args.password

browser = ms.StatefulBrowser(
    soup_config={'features': 'lxml'},
    raise_on_404=True,
    user_agent='Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2272.101 Safari/537.36'
)
browser.set_verbose(2)


# load page
try:
    browser.open(url_login)
    # browser.follow_link("login")
    # login_page = browser.get_current_page()
except ms.utils.LinkNotFoundError:
    print("Link not found ({url_login})")

# select form on page.
form_selector = 'form[action="/users/sign_in"]'
form = browser.select_form(form_selector)
if form:
    print("Form selected:...\n")
    form.print_summary()
    print("\n")
else:
    print("Form with form_selector = {form_selector} not found\n")

# fill in form and submit
browser["user[email]"] = login_email
browser["user[password]"] = login_password
resp: requests.Response = browser.submit_selected()
# print(resp.text)   # .status_code .text (unicode). content (bytes) .url .ok

# now logged in?
cookies = browser.get_cookiejar()
# cookie_dict = cookies.as_dict()
cookie_list = [{'name': c.name, 'value': c.value, 'domain': c.domain, 'path': c.path} for c in cookies]
cookie = cookie_list[0]
#print(cookie_list)
#resp = browser.open(url_login_success)
#current_url = browser.get_url()
# print(current_url)
#assert resp.url == url_login_success
headers = {"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
           "Accept-Encoding": "gzip, deflate, br",
           "Accept-Language": "en-GB,en;q=0.5",
           "Cache-Control": "max-age=0",
           "Connection": "keep-alive",
           # "Cookie": f"__tawkuuid=e::signaturelearninghub.co.uk::ZiABCQv/2R4s/Pc2J7yNau+XkQtWcy49MDem/1wRGKnH49ZMmo32QTyB9ieFRn+W::2; 
           # {cookie['name']}={cookie['value']}; TawkConnectionTime=0",
           "Cookie-Installing-Permission": "required",
           "Host": "www.signaturelearninghub.co.uk",
           "Upgrade-Insecure-Requests": "1",
           "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:70.0) Gecko/20100101 Firefox/70.0"}

browser.session.headers.update(headers)
resp = browser.open('https://www.signaturelearninghub.co.uk/studies/4')
# print(resp.request.headers)
current_url2 = browser.get_url()
# print(resp.url)
page: bs = browser.get_current_page()
# browser.launch_browser()


"""
b'<!DOCTYPE html >\n < html >\n < head >\n < meta name = "viewport" content = "width=device-width, 
initial-scale=1.0" >\n < title > Signature Sso < /title >\n < meta name = "description" content = "Signature Sso" >\n
 < link rel = "stylesheet" media = "all" href = "/assets/application-6963667a2ddbd7ff9bbb547c67ab64262d50057c0457378dcccba1e0d4d1e063.css" data - 
 turbolinks - track = "true" / >\n < script src = "/assets/application-686a7cc9b6e96e2281883d22060201ebdc92e127ef55701c5504e92f36e410b8.js" data - 
 turbolinks - track = "true" > < / script >\n < meta name = "csrf-param" content = "authenticity_token" / >\n < meta name = "csrf-token" 
 content = "STnxxGub5AoZlkr9af7L4LSsbJWkUB1/IOCKyw6c+nEy9QwSChzvQS5WMuipxoAZhQz7myOCnFzkg03Y4mjaGg==" / >\n < /head >\n < body >\n < header >\n 
 < div class = "container logo-container" >\n < div class = "row" >\n < div class = "col-xs-12" > <a href = "/" class = "logo" > 
 <img src = "/assets/signature-logo-83c764f558b2aeb3deeda61465b5ac7ebcf56b4f029083e1adb29acb41ac08f3.jpg" alt = "Signature logo" / > < /a > 
 < / div >\n < /div >\n < /div >\n < div class = "top-nav" >\n < nav class = "navbar" >\n < div class = "container" >\n < div class = "navbar-header" 
 >\n < button type = "button" class = "navbar-toggle collapsed" data - toggle = "collapse" data - target = "#navbar" aria - expanded = "false" aria 
 - controls = "navbar" >\n < span class = "sr-only" > Toggle navigation < /span > <span class = "icon-bar" > < / span > <span class = "icon-bar" > 
 < / span >\n < span class = "icon-bar" > < / span > < / button >\n < a class = "navbar-brand" href = "#" > <span > DASHBOARD < /span > < / a >\n 
 < /div >\n < div id = "navbar" class = "navbar-collapse collapse" >\n < ul class = "nav navbar-nav" >\n < li > <a href = "/" > Dashboard < /a > 
 < / li >\n < li > <a href = "/profiles/13660" > Profile < /a > < / li >\n

<li > <a href = "https://shop.signature.org.uk/account" > Purchases < /a > < / li >\n < li > 
<a href = "https://www.signaturelearninghub.co.uk/sign_in" > Learning Hub < /a > < / li >\n      \n < li > 
<a href = "https://shop.signature.org.uk" > Shop < /a > < / li >\n < li > 
<a rel = "nofollow" data - method = "delete" href = "/users/sign_out" > Sign out < /a > < / li >\n < /ul >\n\n 
< /div >\n < /div >\n < /nav >\n < /div >\n\n\n\n < /header >\n < div class = "container" >\n < div class = "alert alert-success" >\n 
< button type = "button" class = "close" data - dismiss = "alert" aria - hidden = "true" > &times
< / button >\n < div id = "flash_notice" > Signed in successfully. < /div >\n < /div >\n\n 

< section class = "row home-steps" >\n\n < div class = "col col-xs-12 col-sm-4" > 
<div class = "step " > <div class = "num" > <img class = "svg" src =
 "/assets/profile-icon-4ce75da3407c940c4ecf600251e3216c445713ca9617addab978d3ded6b8f120.svg" alt = "Profile icon" / > < /div > <h3 > 
 <a href = "/profiles/13660" > Profile < /a > < / h3 > <p > Manage your profile < /p > <a class = "btn btn-primary" href = "/profiles/13660" > 
 Profile < /a > < / div > < / div >\n < div class = "col col-xs-12 col-sm-4" > <div class = "step " > <div class = "num" > <img class = "svg" 
 src = "/assets/training-resources-icon-b12433fc07db4d65cc4964d2efd6ffd3f140bad76ff927d3fd5245e445253689.svg" alt = "Training resources icon" / > 
 < /div > <h3 > <a href = "https://www.signaturelearninghub.co.uk/sign_in" > Learning Hub < /a > < / h3 > <p > Manage your training resources < /p > 
 <a class = "btn btn-primary" href = "https://www.signaturelearninghub.co.uk/sign_in" > Learning Hub < /a > < / div > < / div >\n < div class = "col 
 col-xs-12 col-sm-4" > <div class = "step " > <div class = "num" > <img class = "svg" 
 src = "/assets/shop-icon-2c7979c132bbccdefe6a4055dff90ab86521b19949fd8708c7430938655c3892.svg" alt = "Shop icon" / > < /div > <h3 > 
 <a href = "https://shop.signature.org.uk/autologin" > Shop < /a > < / h3 > <p > Visit the shop < /p > <a class = "btn btn-primary" 
 href = "https://shop.signature.org.uk/autologin" > Shop < /a > < / div > < / div >\n < div class = "col col-xs-12 col-sm-4" > <div class = "step " > 
 <div class = "num" > <img class = "svg" src = "/assets/purchases-icon-e4c5950038c7a21b3005dfe0816f3305c3d2eb1b5eaf5244d45276e3b5bd3a8c.svg" 
 alt = "Purchases icon" / > < /div > <h3 > <a href = "https://shop.signature.org.uk/account" > Purchases < /a > < / h3 > <p > View your purchases 
 < /p > <a class = "btn btn-primary" href = "https://shop.signature.org.uk/account" > Purchases < /a > < / div > < / div >\n < div class = "col 
 col-xs-12 col-sm-4" > <div class = "step " > <div class = "num" > <img class = "svg" src = "/assets/centre-icon-f3224f0b0421a39b1d48fad8720566d
 cda77e78aa7a9f52fddba9deb71efe9f0.svg" alt = "Centre icon" / > < /div > <h3 > <a href = "https://portal.signature.org.uk/account" > Centre Port
 al < /a > < / h3 > <p > Setup new centre < /p > <a class = "btn btn-primary" href = "https://portal.signature.org.uk/account" > Centre Portal < 
 /a > < / div > < / div >\n  \n  \n < div class = "col col-xs-12 col-sm-4" > <div class = "step " > <div class = "num" > <img class = "svg" src 
 = "/assets/teacher-portal-icon-0cc9076b3e7b5f478e9e551745f54cfd93f20c07943b9ad24ea7fadaca709256.svg" alt = "Teacher portal icon" / > < /div > <
 h3 > <a href = "https://teachers.signature.org.uk/dashboard" > Teacher Directory < /a > < / h3 > <p > Visit teacher directory < /p > <a class 
 = "btn btn-primary" href = "https://teachers.signature.org.uk/dashboard" > Teacher Directory < /a > < / div > < / div >\n\n < /section >\n < /
 div >\n < /body >\n < /html >\n'
"""
