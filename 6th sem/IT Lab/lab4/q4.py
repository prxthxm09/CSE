class stringfunc:
	def __init__(self):
		self.s = ""
	def get_String(self):
		self.s = input("Enter a string: ")
	def print_String(self):
		print(self.s.upper())

if __name__ == '__main__':
	sf = stringfunc()
	sf.get_String()
	sf.print_String()