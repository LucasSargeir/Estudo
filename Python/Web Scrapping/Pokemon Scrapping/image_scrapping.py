from bs4 import BeautifulSoup
from PIL import Image
import requests
import shutil
import os
from PIL import Image
import numpy as np
from ast import literal_eval as make_tuple

total_downloads = 0


def converte_todos_os_gifs(path):
	def convert(src:str, dest:str):
		im = Image.open(src)
		try:
			transparency = im.info['transparency'] 
			im.save(dest, transparency=transparency)
		except:
			im.save(dest)

	arquivos = os.listdir(path)
	for i in arquivos:
		nome,tipo = i.split(".")
		if tipo == "gif":
			past_name = path + i
			new_name = path + nome + ".png"
			convert(past_name, new_name)
			os.remove(past_name)
			print(f"\t\t{past_name} -> {new_name}")

def tranforma_fundo_transparente(path):
	def set_transparent_background(src:str, dest:str, exception=""):

		def change_one_color(src:str, dest:str,last_color: tuple, new_color: tuple):
			im = Image.open(src).convert('RGB')
			data = np.array(im)
			vermelho, verde, azul = data.T
			condicao = (vermelho == last_color[0]) & (verde == last_color[1]) & (azul == last_color[2])
			data[condicao.T] = new_color
			im2 = Image.fromarray(data)
			im2.save(dest)


		def define_cor(*cores):
			dic = {}
			for i in cores:
				if str(i) in dic:
					dic[str(i)] +=1
				else:
					dic[str(i)] = 1

			
			return make_tuple(max(dic, key=lambda c: dic[c]))

		if exception == "relicant_exception":
			change_one_color(src, src, (40,56,64), (56,56,56))

		im = Image.open(src).convert('RGBA')
		data = np.array(im)
		width, height = im.size
		print(f"\tTO: {src}\tFOR: {dest}")
		vermelho, verde, azul, alpha = data.T

		color_ul = (vermelho[0][0], verde[0][0], azul[0][0])
		color_ur = (vermelho[0][height-1], verde[0][height-1], azul[0][height-1])
		color_dl = (vermelho[width-1][0], verde[width-1][0], azul[width-1][0])
		color_dr = (vermelho[width-1][height-1], verde[width-1][height-1], azul[width-1][height-1])

		if data[0][0][3] == 0 or data[height-1][0][3] == 0 or data[0][width-1][3] == 0 or data[height-1][width-1][3] == 0:
			return

		color = define_cor(color_dr, color_dl, color_ul, color_ur)

		for i in range(height):
			for j in range(width):
				actual = data[i][j]
				if i > 0:
					up = data[i-1][j]
				if i < height - 1:
					down = data[i+1][j]
				if j > 0:
					left = data[i][j-1]
				if j < width -1:
					right = data[i][j+1]
				if i > 0 and j > 0:
					ul = data[i-1][j-1]
				if i > 0 and j < width -1:
					ur = data[i-1][j+1]
				if i < height - 1 and j > 0:
					dl = data[i+1][j-1]
				if i < height - 1 and j < width -1:
					dr = data[i+1][j+1]

				cont = 0
				if actual[0] == color[0] and actual[1] == color[1] and actual[2] == color[2]:
					if i > 0:
						if actual[0] == up[0] and actual[1] == up[1] and actual[2] == up[2]:
							cont += 1
					if i < height - 1:
						if actual[0] == down[0] and actual[1] == down[1] and actual[2] == down[2]:
							cont += 1
					if j > 0:
						if actual[0] == left[0] and actual[1] == left[1] and actual[2] == left[2]:
							cont += 1
					if j < width -1:
						if actual[0] == right[0] and actual[1] == right[1] and actual[2] == right[2]:
							cont += 1
					if i > 0 and j > 0:
						if actual[0] == ul[0] and actual[1] == ul[1] and actual[2] == ul[2]:
							cont += 1
					if i > 0 and j < width -1:
							if actual[0] == ur[0] and actual[1] == ur[1] and actual[2] == ur[2]:
								cont += 1
					if i < height - 1 and j > 0:
							if actual[0] == dl[0] and actual[1] == dl[1] and actual[2] == dl[2]:
								cont += 1
					if i < height - 1 and j < width -1:
							if actual[0] == dr[0] and actual[1] == dr[1] and actual[2] == dr[2]:
								cont += 1

				if i == 0 or i == height -1 or j == 0 or j == width-1:
					if (i == 0 and j == 0) or (i == height -1 and j == width-1) or (i == height -1 and j == 0) or (i == 0 and j == width-1):
						if cont >= 3:
							data[i][j][3] = 0
					elif cont >= 4:
						data[i][j][3] = 0
				else:
					if cont >= 5:
						data[i][j][3] = 0
		
		im2 = Image.fromarray(data)
		im2.save(dest)

	arquivos = os.listdir(path)
	for i in arquivos:
		if "179" in i and "RS" in path:
			set_transparent_background(path+i,path+i, "relicant_exception")
		else:
			set_transparent_background(path+i,path+i)
		print(f"\t\tRemovendo fundo de {i}")

def converte_gen3_gifs():
	em_path = "./assets/gen_3/Em/"
	rs_path = "./assets/gen_3/RS/"
	frlg_path = "./assets/gen_3/FRLG/"

	print("\tConvertendo Gen 3 Em version")
	converte_todos_os_gifs(em_path+"shiny/") 
	converte_todos_os_gifs(em_path+"normal/") 
	
	print("\tConvertendo Gen 3 RS version")
	converte_todos_os_gifs(rs_path+"shiny/") 
	converte_todos_os_gifs(rs_path+"normal/") 

	print("\tConvertendo Gen 3 FRLG version")
	converte_todos_os_gifs(frlg_path+"shiny/") 
	converte_todos_os_gifs(frlg_path+"normal/") 

def tranforma_backgroun_gen3():
	em_path = "./assets/gen_3/Em/"
	rs_path = "./assets/gen_3/RS/"
	frlg_path = "./assets/gen_3/FRLG/"

	print("\tTransformando fundos Gen 3 Em version shiny")
	tranforma_fundo_transparente(em_path+"shiny/") 
	print("\tTransformando fundos Gen 3 Em version normal")
	tranforma_fundo_transparente(em_path+"normal/") 
	
	print("\tTransformando fundos Gen 3 RS version shiny")
	tranforma_fundo_transparente(rs_path+"shiny/") 
	print("\tTransformando fundos Gen 3 RS version normal")
	tranforma_fundo_transparente(rs_path+"normal/") 

	print("\tTransformando fundos Gen 3 FRLG version shiny")
	tranforma_fundo_transparente(frlg_path+"shiny/") 
	print("\tTransformando fundos Gen 3 FRLG version normal")
	tranforma_fundo_transparente(frlg_path+"normal/") 

def download_imagem(url, path):
	filename = url.split("/")[-1]
	if "-g" in filename:
		url2 = url.replace("-g", "")
		download_imagem(url2, path)
	if os.path.isfile(path+filename):
		return
	global total_downloads
	total_downloads += 1
	r = requests.get(url, stream = True)
	if r.status_code == 200:
		r.raw.decode_content = True
		with open(path+filename,'wb') as f:
			shutil.copyfileobj(r.raw, f)
			print('\tImage sucessfully Downloaded: ',filename)
	else:
		print('\tImage Couldn\'t be retreived')

def get_gen8_names(position = 1):
	url = "https://serebii.net/pokedex-swsh/bulbasaur/"
	html = requests.get(url).content
	soup = BeautifulSoup(html, 'html.parser')
	forms = soup.find_all("form")
	nomes = []
	for i in forms:
		if "nav" in str(i.get("name")):
			select = i.find("select")
			for j in select:
				string = j.string.split(" ")
				if string[0].isnumeric():
					if("Nidoran♀" in string[1]):
						string[1] = "nidoranf"
					if("Nidoran♂" in string[1]):
						string[1] = "nidoranm"
					if("Mr." == string[1] or "Mime" == string[1] or "Tapu" == string[1] or "Type:" == string[1]):
						string[1] += string[2]
					nomes.append(string[position].lower())
	return nomes

def copy_gen3_identical_sprites():
	print("Copiando sprites identicos [RB <--> FRLG]")
	deoxys_shiny_a = "./assets/gen_3/RS/shiny/202a.gif"
	deoxys_shiny_d = "./assets/gen_3/RS/shiny/202d.gif"
	if not os.path.isfile("./assets/gen_3/RS/shiny/202s.png"):
		deoxys_shiny_s = "./assets/gen_3/Em/normal/386s.png"
	else:
		deoxys_shiny_s = "./assets/gen_3/RS/shiny/202s.png"
	deoxys_shiny_n = "./assets/gen_3/RS/shiny/202.gif"
	
	deoxys_normal_a = "./assets/gen_3/FRLG/normal/386-f.gif"
	deoxys_normal_d = "./assets/gen_3/FRLG/normal/386-l.gif"
	deoxys_normal_s = "./assets/gen_3/Em/normal/386.png"
	deoxys_normal_n = "./assets/gen_3/RS/normal/202.gif"


	# Ruby & Saphire
	if not os.path.isfile("./assets/gen_3/RS/shiny/202s.png"):
		dest = shutil.copy(deoxys_shiny_s,"./assets/gen_3/RS/shiny/202s.png")
		deoxys_shiny_s = str(dest) 
		os.remove("./assets/gen_3/Em/normal/386s.png")
		print(dest)
	# Emerald
	if not os.path.isfile("./assets/gen_3/Em/shiny/386a.gif"):
		dest = shutil.copy(deoxys_shiny_a,"./assets/gen_3/Em/shiny/386a.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/Em/shiny/386d.gif"):
		dest = shutil.copy(deoxys_shiny_d,"./assets/gen_3/Em/shiny/386d.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/Em/shiny/386s.png"):
		dest = shutil.copy(deoxys_shiny_s,"./assets/gen_3/Em/shiny/386s.png") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/Em/shiny/386.gif"):
		dest = shutil.copy(deoxys_shiny_n,"./assets/gen_3/Em/shiny/386.gif") 
		print(dest)

	# FRLG
	if not os.path.isfile("./assets/gen_3/FRLG/shiny/386a.gif"):
		dest = shutil.copy(deoxys_shiny_a,"./assets/gen_3/FRLG/shiny/386a.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/FRLG/shiny/386d.gif"):
		dest = shutil.copy(deoxys_shiny_d,"./assets/gen_3/FRLG/shiny/386d.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/FRLG/shiny/386s.png"):
		dest = shutil.copy(deoxys_shiny_s,"./assets/gen_3/FRLG/shiny/386s.png") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/FRLG/shiny/386.gif"):
		dest = shutil.copy(deoxys_shiny_n,"./assets/gen_3/FRLG/shiny/386.gif") 
		print(dest)

	# Ruby & Saphire
	if not os.path.isfile("./assets/gen_3/RS/normal/386a.gif"):
		dest = shutil.copy(deoxys_normal_a,"./assets/gen_3/RS/normal/202a.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/RS/normal/386d.gif"):
		dest = shutil.copy(deoxys_normal_d,"./assets/gen_3/RS/normal/202d.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/RS/normal/386s.png"):
		dest = shutil.copy(deoxys_normal_s,"./assets/gen_3/RS/normal/202s.png") 
		print(dest)

	# Emerald
	if not os.path.isfile("./assets/gen_3/Em/normal/386a.gif"):
		dest = shutil.copy(deoxys_normal_a,"./assets/gen_3/Em/normal/386a.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/Em/normal/386d.gif"):
		dest = shutil.copy(deoxys_normal_d,"./assets/gen_3/Em/normal/386d.gif") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/Em/normal/386s.png"):
		dest = shutil.copy(deoxys_normal_s,"./assets/gen_3/Em/normal/386s.png") 
		deoxys_normal_s = str(dest) 
		os.remove("./assets/gen_3/Em/normal/386.png")
		print(dest)
	if not os.path.isfile("./assets/gen_3/Em/normal/386.gif"):
		dest = shutil.copy(deoxys_normal_n,"./assets/gen_3/Em/normal/386.gif") 
		print(dest)

	# FRLG
	if not os.path.isfile("./assets/gen_3/FRLG/normal/386a.gif"):
		dest = shutil.copy(deoxys_normal_a,"./assets/gen_3/FRLG/normal/386a.gif") 
		os.remove("./assets/gen_3/FRLG/normal/386-f.gif")
		print(dest)
	if not os.path.isfile("./assets/gen_3/FRLG/normal/386d.gif"):
		dest = shutil.copy(deoxys_normal_d,"./assets/gen_3/FRLG/normal/386d.gif") 
		os.remove("./assets/gen_3/FRLG/normal/386-l.gif")
		print(dest)
	if not os.path.isfile("./assets/gen_3/FRLG/normal/386s.png"):
		dest = shutil.copy(deoxys_normal_s,"./assets/gen_3/FRLG/normal/386s.png") 
		print(dest)
	if not os.path.isfile("./assets/gen_3/FRLG/normal/386.gif"):
		dest = shutil.copy(deoxys_normal_s,"./assets/gen_3/FRLG/normal/386.gif") 
		print(dest)

def copy_gen4_identical_sprites():
	print("Copiando sprites identicos [RB <--> FRLG]")
	hgss_shiny = "./assets/gen_4/HGSS/shiny/"
	dp_shiny =  "./assets/gen_4/DP/shiny/"
	hgss_normal = "./assets/gen_4/HGSS/normal/"
	dp_normal =  "./assets/gen_4/DP/normal/"

	arquivos = os.listdir(dp_normal)
	for i in arquivos:
		if not os.path.isfile(hgss_normal+i):
			dest = shutil.copy(dp_normal+i, hgss_normal+i) 
			print(dest)

	arquivos = os.listdir(dp_shiny)
	for i in arquivos:
		if not os.path.isfile(hgss_shiny+i):
			dest = shutil.copy(dp_shiny+i, hgss_shiny+i) 
			print(dest)

def verifica_todos(gen):
	total = 0
	paths = []
	if gen == 0:
		return 
	if gen == 1:
		total = 151
		paths = [["./assets/gen_1/Green/"], ["./assets/gen_1/RB/"],["./assets/gen_1/Yellow/"]]
	elif gen == 2:
		total = 251
		paths = [["./assets/gen_2/C/shiny/", "./assets/gen_2/C/normal/"], ["./assets/gen_2/G/shiny/", "./assets/gen_2/G/normal/"], ["./assets/gen_2/S/shiny/", "./assets/gen_2/S/normal/"]]
	elif gen == 3:
		total = 386
		paths = [["./assets/gen_3/Em/shiny/", "./assets/gen_3/Em/normal/"], ["./assets/gen_3/FRLG/shiny/", "./assets/gen_3/FRLG/normal/"], ["./assets/gen_3/RS/shiny/", "./assets/gen_3/RS/normal/"]]
	elif gen == 4:
		total = 493
		paths = [["./assets/gen_4/DP/shiny/", "./assets/gen_4/DP/normal/"], ["./assets/gen_4/HGSS/shiny/", "./assets/gen_4/HGSS/normal/"]]
	elif gen == 5:
		total = 649
		paths = [["./assets/gen_5/shiny/", "./assets/gen_5/normal/"]]
	elif gen == 6:
		total = 721
		paths = [["./assets/gen_6/shiny/", "./assets/gen_6/normal/"]]
	elif gen == 7:
		total = 809
		paths = [["./assets/gen_7/shiny/", "./assets/gen_7/normal/"]]
	elif gen == 8:
		total = get_gen8_names(0)
		paths = [["./assets/gen_8/shiny/", "./assets/gen_8/normal/"]]
	else:
		return []

	missing = {}

	the_range = range(1,total+1) if gen < 8 else total

	for i in the_range:
		for j in range(len(paths)):
			for k in range(len(paths[j])):
				path_png = os.path.isfile(f"{paths[j][k]}{i:03}.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}.png")
				path_gif = os.path.isfile(f"{paths[j][k]}{i:03}.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}.gif")
				if not path_png and not path_gif:
					path_png_m = os.path.isfile(f"{paths[j][k]}{i:03}-m.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-m.png")
					path_gif_m = os.path.isfile(f"{paths[j][k]}{i:03}-m.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-m.gif")
					path_png_f = os.path.isfile(f"{paths[j][k]}{i:03}-f.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-f.png")
					path_gif_f = os.path.isfile(f"{paths[j][k]}{i:03}-f.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-f.gif")
					path_png_w = os.path.isfile(f"{paths[j][k]}{i:03}-w.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-w.png")
					path_gif_w = os.path.isfile(f"{paths[j][k]}{i:03}-w.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-w.gif")
					path_png_e = os.path.isfile(f"{paths[j][k]}{i:03}-e.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-e.png")
					path_gif_e = os.path.isfile(f"{paths[j][k]}{i:03}-e.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-e.gif")
					path_png_a = os.path.isfile(f"{paths[j][k]}{i:03}-a.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-a.png")
					path_gif_a = os.path.isfile(f"{paths[j][k]}{i:03}-a.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-a.gif")
					path_png_o = os.path.isfile(f"{paths[j][k]}{i:03}-o.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-o.png")
					path_gif_o = os.path.isfile(f"{paths[j][k]}{i:03}-o.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-o.gif")
					path_png_l = os.path.isfile(f"{paths[j][k]}{i:03}-l.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-l.png")
					path_gif_l = os.path.isfile(f"{paths[j][k]}{i:03}-l.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-l.gif")
					path_png_s = os.path.isfile(f"{paths[j][k]}{i:03}-s.png") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-s.png")
					path_gif_s = os.path.isfile(f"{paths[j][k]}{i:03}-s.gif") if gen < 8 else os.path.isfile(f"{paths[j][k]}{i}-s.gif")

					if not path_png_f and not path_png_m and not path_gif_f and not path_gif_m and not path_gif_w and not path_png_w and not path_png_e and not path_gif_e and not path_png_a and not path_gif_a and not path_png_o and not path_gif_o and not path_png_l and not path_gif_l and not path_png_s and not path_gif_s:
						key = f"{paths[j][k]}{i:03}.png" if gen < 8 else f"{paths[j][k]}{i}.png"
						missing[key] = f"{i:03}.png" if gen < 8 else f"{i}.png"
				
	return missing

def cria_estrutura_dir():
	local = './'
	exist = os.listdir(local)
	folder = "assets"

	if folder not in exist:
		local = os.path.join('.',folder)
		os.mkdir(local)
		local2 = os.path.join(local,"gen_1")
		os.mkdir(local2)
		local3 = os.path.join(local2,"Green")
		os.mkdir(local3)
		local3 = os.path.join(local2,"RB")
		os.mkdir(local3)
		local3 = os.path.join(local2,"Yellow")
		os.mkdir(local3)
		

		local2 = os.path.join(local,"gen_2")
		os.mkdir(local2)
		local3 = os.path.join(local2,"C")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		local3 = os.path.join(local2,"G")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		local3 = os.path.join(local2,"S")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		
		
		local2 = os.path.join(local,"gen_3")
		os.mkdir(local2)
		local3 = os.path.join(local2,"Em")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		local3 = os.path.join(local2,"FRLG")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		local3 = os.path.join(local2,"RS")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		
		local2 = os.path.join(local,"gen_4")
		os.mkdir(local2)
		local3 = os.path.join(local2,"DP")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		local3 = os.path.join(local2,"HGSS")
		os.mkdir(local3)
		local4 = os.path.join(local3,"normal")
		os.mkdir(local4)
		local4 = os.path.join(local3,"shiny")
		os.mkdir(local4)
		
		local2 = os.path.join(local,"gen_5")
		os.mkdir(local2)
		local3 = os.path.join(local2,"normal")
		os.mkdir(local3)
		local3 = os.path.join(local2,"shiny")
		os.mkdir(local3)
		
		local2 = os.path.join(local,"gen_6")
		os.mkdir(local2)
		local3 = os.path.join(local2,"normal")
		os.mkdir(local3)
		local3 = os.path.join(local2,"shiny")
		os.mkdir(local3)
		
		local2 = os.path.join(local,"gen_7")
		os.mkdir(local2)
		local3 = os.path.join(local2,"normal")
		os.mkdir(local3)
		local3 = os.path.join(local2,"shiny")
		os.mkdir(local3)

		local2 = os.path.join(local,"gen_8")
		os.mkdir(local2)
		local3 = os.path.join(local2,"normal")
		os.mkdir(local3)
		local3 = os.path.join(local2,"shiny")
		os.mkdir(local3)

		local2 = os.path.join(local,"Go")
		os.mkdir(local2)
		local3 = os.path.join(local2,"normal")
		os.mkdir(local3)
		local3 = os.path.join(local2,"shiny")
		os.mkdir(local3)
		
	else:
		return

def download_pkmn_go(aditional = "001"):

	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokemongo/pokemon/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/pokemongo/pokemon/" in str(i.get('src')) or "/pokemongo/pokemon/shiny/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/pokemongo/pokemon/shiny/" in str(i.get('src')):
				download_imagem(link, "./assets/Go/shiny/")
				print(f"\t[Go] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/Go/normal/")
				print(f"\t[Go] - Downloading {aditional} normal sprite...")

def download_gen8(aditional = "bulbasaur"):
	default_url = "https://serebii.net"
	path = "/pokedex-swsh/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
			if "/swordshield/pokemon/" in str(i.get('src')) or "/Shiny/SWSH/" in str(i.get('src')):
				link = default_url+i.get('src')
				if "/Shiny/SWSH/" in str(i.get('src')):
					download_imagem(link, "./assets/gen_8/shiny/")
					print(f"\t[GEN 8] - Downloading {aditional} shiny sprite...")
				else:
					download_imagem(link, "./assets/gen_8/normal/")
					print(f"\t[GEN 8] - Downloading {aditional} normal sprite...")

def download_gen7(aditional = "001"):
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex-sm/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/sunmoon/pokemon/" in str(i.get('src')) or "/Shiny/SM/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/Shiny/SM/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_7/shiny/")
				print(f"\t[GEN 7] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/gen_7/normal/")
				print(f"\t[GEN 7] - Downloading {aditional} normal sprite...")

def download_gen6(aditional = "001"):
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex-xy/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/xy/pokemon/" in str(i.get('src')) or "/Shiny/XY/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/Shiny/XY/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_6/shiny/")
				print(f"\t[GEN 6] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/gen_6/normal/")
				print(f"\t[GEN 6] - Downloading {aditional} normal sprite...")

def download_gen5(aditional = "001"):
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex-bw/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/blackwhite/pokemon/" in str(i.get('src')) or "/Shiny/BW/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/Shiny/BW/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_5/shiny/")
				print(f"\t[GEN 5] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/gen_5/normal/")
				print(f"\t[GEN 5] - Downloading {aditional} normal sprite...")

def download_gen4(aditional = "001"):
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex-dp/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/pokearth/sprites/pt/" in str(i.get('src')) or "/Shiny/Pl/" in str(i.get('src')) or "/pokearth/sprites/dp/" in str(i.get('src')) or "/pokearth/sprites/hgss/" in str(i.get('src')) or "/diamondpearl/pokemon/" in str(i.get('src')) or "/Shiny/DP/" in str(i.get('src')) or "/heartgoldsoulsilver/pokemon/" in str(i.get('src')) or "/Shiny/HGSS/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/Shiny/DP/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_4/DP/shiny/")
				print(f"\t[GEN 4 DP] - Downloading {aditional} shiny sprite...")
			elif "/diamondpearl/pokemon/" in str(i.get('src')) or "/pokearth/sprites/dp/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_4/DP/normal/")
				print(f"\t[GEN 4 DP] - Downloading {aditional} normal sprite...")
			elif "/Shiny/HGSS/" in str(i.get('src')) or "/Shiny/Pl/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_4/HGSS/shiny/")
				print(f"\t[GEN 4 HGSS] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/gen_4/HGSS/normal/")
				print(f"\t[GEN 4 HGSS] - Downloading {aditional} normal sprite...")

def download_gen3(aditional = "001"):
	aditional2 = aditional
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex-rs/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")
	count = 0 
	number_advanced = "0"
	for i in imagem:
		if "/pokemon_advance/" in str(i.get('src')) or "/Shiny/RuSa/" in str(i.get('src')) or "/red_green/pokemon/" in str(i.get('src')) or "/Shiny/FRLG/" in str(i.get('src')) or "/emerald/pokemon/" in str(i.get('src')) or "/Shiny/Em/" in str(i.get('src')):
			link = default_url+i.get('src')
			count = count + 1
			if "/Shiny/FRLG/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_3/FRLG/shiny/")
				print(f"\t[GEN 3 FRLG] - Downloading {aditional} shiny sprite...")
			elif "/red_green/pokemon/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_3/FRLG/normal/")
				print(f"\t[GEN 3 FRLG] - Downloading {aditional} normal sprite...")
			elif "/Shiny/Em/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_3/Em/shiny/")
				print(f"\t[GEN 3 Em] - Downloading {aditional} shiny sprite...")
			elif "/emerald/pokemon/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_3/Em/normal/")
				print(f"\t[GEN 3 Em] - Downloading {aditional} normal sprite...")
			elif "/Shiny/RuSa/" in str(i.get('src')): 
				download_imagem(link, "./assets/gen_3/RS/shiny/")
				number_advanced = i.get('src').split('.')[0].split('/')[-1]
				print(f"\t[GEN 3 RS] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/gen_3/RS/normal/")
				print(f"\t[GEN 3 RS] - Downloading {aditional} normal sprite...")

	if count == 4 and number_advanced != "0":
		path_rs = "./assets/gen_3/RS/shiny/"+number_advanced+".gif"
		path_frlg = "./assets/gen_3/FRLG/shiny/"+aditional2+".gif"
		print("\t Copiando => "+path_rs+" => "+path_frlg+" ...")
		shutil.copy(path_rs, path_frlg) 
		shutil.copy(path_rs.replace("shiny", "normal"), path_frlg.replace("shiny", "normal")) 

def download_gen2(aditional = "001"):
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex-gs/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/pokearth/sprites/gold/" in str(i.get('src')) or "/Shiny/Gold/" in str(i.get('src')) or "/pokearth/sprites/silver/" in str(i.get('src')) or "/Shiny/Silver/" in str(i.get('src')) or "/pokearth/sprites/crystal/" in str(i.get('src')) or "/Shiny/Crystal/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/Shiny/Gold/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_2/G/shiny/")
				print(f"\t[GEN 2 G] - Downloading {aditional} shiny sprite...")
			elif "/pokearth/sprites/gold/"in str(i.get('src')):
				download_imagem(link, "./assets/gen_2/G/normal/")
				print(f"\t[GEN 2 G] - Downloading {aditional} normal sprite...")
			elif "/Shiny/Silver/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_2/S/shiny/")
				print(f"\t[GEN 2 S] - Downloading {aditional} shiny sprite...")
			elif "/pokearth/sprites/silver/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_2/S/normal/")
				print(f"\t[GEN 2 S] - Downloading {aditional} normal sprite...")
			elif "/Shiny/Crystal/" in str(i.get('src')): 
				download_imagem(link, "./assets/gen_2/C/shiny/")
				print(f"\t[GEN 2 C] - Downloading {aditional} shiny sprite...")
			else:
				download_imagem(link, "./assets/gen_2/C/normal/")
				print(f"\t[GEN 2 C] - Downloading {aditional} normal sprite...")

def download_gen1(aditional = "001"):
	aditional += ".shtml"
	default_url = "https://serebii.net"
	path = "/pokedex/"
	html = requests.get(default_url+path+aditional).content
	print("Baixando de: "+ default_url+path+aditional)
	soup = BeautifulSoup(html, 'html.parser')
	imagem = soup.find_all("img")

	for i in imagem:
		if "/pokearth/sprites/green/" in str(i.get('src')) or "/pokearth/sprites/rb/" in str(i.get('src')) or "/pokearth/sprites/yellow/" in str(i.get('src')):
			link = default_url+i.get('src')
			if "/pokearth/sprites/green/"  in str(i.get('src')):
				download_imagem(link, "./assets/gen_1/Green/")
				print(f"\t[GEN 1 Green] - Downloading {aditional} normal sprite...")
			elif "/pokearth/sprites/rb/" in str(i.get('src')):
				download_imagem(link, "./assets/gen_1/RB/")
				print(f"\t[GEN 1 RB] - Downloading {aditional} normal sprite...")
			else:
				download_imagem(link, "./assets/gen_1/Yellow/")
				print(f"\t[GEN 1 Yellow] - Downloading {aditional} normal sprite...")

def download_images(gens = [0,1,2,3,4,5,6,7,8], ini = 1):
	
	cria_estrutura_dir()

	if 1 in gens:
		print("----------------------------[STARTING GEN 1]----------------------------")
		#download GEN 1
		for i in range(ini, 151 + 1):
			download_gen1(f"{i:03}")

	if 2 in gens:
		print("\n----------------------------[STARTING GEN 2]----------------------------")
		#download GEN 2
		for i in range(ini, 251 + 1):
			download_gen2(f"{i:03}")

	if 3 in gens:
		print("\n----------------------------[STARTING GEN 3]----------------------------")
		#download GEN 3
		for i in range(1, 386 + 1):
			download_gen3(f"{i:03}")

	if 4 in gens:
		print("\n----------------------------[STARTING GEN 4]----------------------------")
		#download GEN 4
		for i in range(ini, 493 + 1):
			download_gen4(f"{i:03}")

	if 5 in gens:
		print("\n----------------------------[STARTING GEN 5]----------------------------")	
		#download GEN 5
		for i in range(ini, 649 + 1):
			download_gen5(f"{i:03}")

	if 6 in gens:
		print("\n----------------------------[STARTING GEN 6]----------------------------")
		#download GEN 6
		for i in range(ini, 721 + 1):
			download_gen6(f"{i:03}")

	if 7 in gens:
		print("\n----------------------------[STARTING GEN 7]----------------------------")
		#download GEN 7
		for i in range(ini, 809 + 1):
			download_gen7(f"{i:03}")

	if 8 in gens:
		print("\n----------------------------[STARTING GEN 8]----------------------------")
		#download GEN 8
		for i in get_gen8_names():
			download_gen8(i)

	if 0 in gens:
		print("----------------------------[STARTING PKM GO]----------------------------")
		#download GEN 1
		for i in range(ini, 721 + 1):
			download_pkmn_go(f"{i:03}")

if __name__ == "__main__":
	
	op = -1
	while op != 6:
		print("\n--------------------[MENU]--------------------")
		print("\n[1] - Download Imagens")
		print("[2] - Verificar imagems baixadas")
		print("[3] - Copiar Sprites Reutilizados de em versões")
		print("[4] - Converter Gifs Gen 3 to PNG")
		print("[5] - Aplicar transparencia nos Gifs Gen 3 convertidos")
		print("\n[6] - Sair")
		op = int(input("-> "))

		if op == 1:
			print("\n\t---------------[DOWNLOAD]---------------\n")
			inputs = input("\tEntre com as gerações que deseja baixar\n\tseparados por espaço.\n\t0 = Pokemon Go\n\n\tInsira uma geração não existente para cancelar.\t-> ")
			gens = [int(i) for i in inputs.split(' ')]
			download_images(gens)
			print(f"\tTotal de downloads: {total_downloads}")
		elif op == 2:
			print("\n\t---------------[CHECK UP]---------------\n")
			inputs = input("\tEntre com as gerações que deseja checar\n\tseparados por espaço.\n\n\t[0] - Sair\n\t-> ")
			gens = [int(i) for i in inputs.split(' ')]
			for i in gens:
				print("\tGen "+str(i)+" => "+str(verifica_todos(i)).replace(",","\n\t"))
		elif op == 3:
			print("\n\t---------------[COPIANDO]---------------\n")
			gen = -1
			while gen != 3:
				gen = int(input("\t[1] - RS - FRLG - Em\n\tCopia os sprites do Deoxys para todas as\n\tversões.\n\n\t[2] - DP - HGSS\n\tCopia todos os sprites faltantes em HGSS,\n\tque são copiados do DP.\n\n\t[3] - Cancelar\n\t-> "))
				if gen == 1:
					copy_gen3_identical_sprites()
				elif gen == 2:
					copy_gen4_identical_sprites()
				elif gen == 3:
					print()
				else:
					print("\tComando inválido! Tente novamente")
		elif op == 4:
			print("\n\t--------------[CONVERTENDO]-------------\n")
			converte_gen3_gifs()
		elif op == 5:
			print("\n\t-------------[TRANFORMANDO]-------------\n")
			tranforma_backgroun_gen3()
		elif op == 6:
			print("Saindo...")
		else:
			print("Comando inválido! Tente novamente")