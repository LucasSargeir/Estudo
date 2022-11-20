import os
import cv2
import pytesseract
from PIL import Image
from image_filter import *

images_dir = './images/'
convert_images_dir = './images-converted/%'


def text_extract(file):
	print(f'Extracting text...')
	
	file_dir = images_dir + file
	new_file_dir = convert_images_dir + file

	img = Image.open(file_dir).convert('RGB')

	new_file_dir = new_file_dir.replace('%', 'filtered-')
	img, width, height = noise_reduction(img)
	img.save(new_file_dir)

	text = pytesseract.image_to_string(new_file_dir)
	text_filtered = ''

	for i in text:
		ord_i = ord(i)
		if (ord_i >= 48 and ord_i <= 57) or (ord_i >= 65 and ord_i <= 90):
			text_filtered += i
	
	return text_filtered, width, height

def QR_extract(file):

	print(f'Extracting QR...')

	file_dir = images_dir + file
	new_file_dir = convert_images_dir + file
	
	img = Image.open(file_dir).convert('RGB')

	new_file_dir = new_file_dir.replace('%', 'filtered-')
	img, width, height = noise_reduction(img)
	img.save(new_file_dir)

	im = cv2.imread(new_file_dir)
	det = cv2.QRCodeDetector()
	retval, points, straight_qrcode = det.detectAndDecode(im)
	return retval, points, straight_qrcode

def create_structure():
	local = './'
	exist = os.listdir(local)
	folder1 = 'images'
	folder2 = 'images-converted'

	if folder1 not in exist:
		local = os.path.join('.',folder1)
		os.mkdir(local)
		print("Use the path ./images to store your photos")

	if folder2 not in exist:
		local = os.path.join('.',folder2)
		os.mkdir(local)

def rename_files():
	local = './images/'
	files = os.listdir(local)
	cont = 1
	for f in files:
		extension = f.split('.')
		while os.path.isfile(local + f'teste-{cont}.{extension[-1]}'):
			cont += 1
		os.rename(local + f, local + f'teste-{cont}.{extension[-1]}')
		cont += 1

def full_extract_from_path():
	result = ''
	dictionary = ''

	arquivos = os.listdir(images_dir)

	for a in arquivos:
		
		print(f'Searching in {images_dir}{a}...')

		height = 0
		width = 0
		text, points, straight_qrcode = QR_extract(a)
		
		if points is None:
			print('[QR] not found')
			text, width, height = text_extract(a)

			if text != '':
				print('[Text] extract sucessfully')
			else:
				print('[Text] not found')

		else:
			print('[QR] found sucessfully')

		if height > width:
			dictionary += f'{text}\tATTENTION\t{a}\n'
			result += f'{text}\tATTENTION\n'
		else:
			dictionary += f'{text}\t\t\t{a}\n'
			result += f'{text}\n'

		print()

	return result, dictionary


if __name__ == '__main__':

	create_structure()
	rename_files()

	result, dictionary = full_extract_from_path()

	file_cod = open('codigos.txt', 'w')
	file_dest_ori = open('de-para.txt', 'w')

	file_cod.write(result)
	file_cod.close()

	file_dest_ori.write(dictionary)
	file_dest_ori.close()

	print(f'\nRESULTS\n\n')
	print(result)
