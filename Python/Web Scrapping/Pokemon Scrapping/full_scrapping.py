from image_scrapping import *

if __name__ == "__main__":
	download_images()
	copy_gen4_identical_sprites()
	copy_gen3_identical_sprites()
	converte_gen3_gifs()
	print("Sprites faltantes na gen 1:\n" + str(verifica_todos(1)).replace(",", "\t"))
	print("Sprites faltantes na gen 2:\n" + str(verifica_todos(2)).replace(",", "\t"))
	print("Sprites faltantes na gen 3:\n" + str(verifica_todos(3)).replace(",", "\t"))
	print("Sprites faltantes na gen 4:\n" + str(verifica_todos(4)).replace(",", "\t"))
	print("Sprites faltantes na gen 5:\n" + str(verifica_todos(5)).replace(",", "\t"))
	print("Sprites faltantes na gen 6:\n" + str(verifica_todos(6)).replace(",", "\t"))
	print("Sprites faltantes na gen 7:\n" + str(verifica_todos(7)).replace(",", "\t"))
	print("Sprites faltantes na gen 8:\n" + str(verifica_todos(8)).replace(",", "\t"))