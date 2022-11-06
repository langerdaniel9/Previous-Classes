from bs4 import BeautifulSoup
from urllib.request import Request, urlopen

req = Request('https://mechanicalkeyboards.com/shop/index.php?l=product_list&c=1',
              headers={'User-Agent': 'Mozilla/5.0'})
webpage = urlopen(req).read()
content = BeautifulSoup(webpage, "html.parser")
print(content)
