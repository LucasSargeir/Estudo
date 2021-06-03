import requests
from bs4 import BeautifulSoup
from decouple import config

count = 0

url = config('URL')
payload = { f"entry.{config('ENTRY_NUMBER')}": f"{config('ENTRY_NAME')}",
			F"entry.{config('ENTRY_NUMBER')}_sentinel": '',
			'fvv': config('FVV'),
			'draftResponse': config('DRAFT_RESPONSE'),
			'pageHistory': config('PAGE_HISTORY'),
			'fbzx': config('FBZX')}

print(payload)

while(1 == 1):
	
	r = requests.post(url, data=payload).content

	soup = BeautifulSoup(r, 'html.parser')
	response = soup.find('div', class_='freebirdFormviewerViewResponseConfirmationMessage')

	count += 1
	
	print(f"{response.text} Voted {count} times")
