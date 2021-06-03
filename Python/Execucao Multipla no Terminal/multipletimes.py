import os
import sys

times = 1

if __name__ == "__main__":

	if len(sys.argv) < 3:
		command = input("Entre com o comando desejado: ")
		times = int(input("Entre com o numero de repetições: "))
	else:
		times = int(sys.argv[1])
		command = ''
		for i in range(2,len(sys.argv)):
			command += sys.argv[i] + " "


	for i in range(0, times):
		os.system(f'gnome-terminal -- {command}')