
class Scramble:

	def __init__(self, limit):

		self.limit = limit
		self.possible_moves = ["R", "L", "F", "B", "D", "U", "R#", "L#", "F#", "B#", "D#", "U#", "R2", "L2", "F2", "B2", "D2", "U2"]
		self.scrambles = self.possible_moves
		self.oposite_moves = {	"2": "",
								"#": "",
								"R": "R#", 
								"L": "L#", 
								"F": "F#",
								"B": "B#",
								"D": "D#",
								"U": "U#",
								"R#": "R",
								"L#": "L",
								"F#": "F",
								"B#": "B",
								"D#": "D",
								"U#": "U",
								"R2": "R2",
								"L2": "L2",
								"F2": "F2",
								"B2": "B2",
								"D2": "D2",
								"U2": "U2"}

	def generate_scrambles(self, move_index = 0, count = 1, doing_stack = 1):
		
		if count < self.limit:
			
			if doing_stack == 1:
				self.generate_scrambles(count = count + 1)
				print(f'Scrambles with {self.limit - count + 1} moves ends')

			if move_index < len(self.possible_moves) - 1 :

				new_scrambles = []

				for s in self.scrambles:
					last_move = (s[-len(self.possible_moves[move_index])::]).strip()
					if self.possible_moves[move_index] != last_move and self.possible_moves[move_index] != self.oposite_moves[last_move]:
						new_scrambles.append(s + " " + self.possible_moves[move_index])

				self.generate_scrambles(move_index + 1, count, 0)
				self.scrambles = self.scrambles + new_scrambles

		else: 
			print(f'Scrambles with {1} move ends')


	def save_scrambles(self, filename):

			file = open(filename, "w")

			file.write(str(self.scrambles).replace(', ','\n').replace('\'','').replace('[', '').replace(']','').replace('#', '\''))
			#.replace('\'','').replace('[', '').replace(']','').replace('#', '\'')
			print(f'\n{len(self.scrambles)} scrambles generated')
			file.close()




if __name__ ==  '__main__':


	num = int(input("Entre com o numero de movimentos que você deseja: "))
	scrambles = Scramble(num)
	scrambles.generate_scrambles()
	scrambles.save_scrambles('scrambles.txt')