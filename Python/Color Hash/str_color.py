def str_to_color(word, gray_scale = False):
	num = ''
	for w in word:
		num += str(ord(w))
	
	red = 0
	green = 0
	blue = 0

	m = len(num)

	for i in range(m):
		if (i+1) % 3 == 0:
			blue += int(num[i]) * m 
		elif (i+1) % 2 == 0:
			green += int(num[i]) * m
		else:	
			red += int(num[i]) * m

	while red > 255:
		red -= 256

	while green > 255:
		green -= 256

	while blue > 255:
		blue -= 256

	if gray_scale:
		medium = (red + blue + green)//3
		red = medium
		green = medium
		blue = medium

	return red, green, blue

if __name__ == "__main__":

	print(str_to_color('Lucas'))
	print(str_to_color('Lucas', gray_scale = True))

