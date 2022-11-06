from bs4 import BeautifulSoup
import requests

url = "http://theaveragejoe.org"
response = requests.get(url)
soup = BeautifulSoup(response.text, 'html.parser')
print(soup)
