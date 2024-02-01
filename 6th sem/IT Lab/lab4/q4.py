 # 4. Write a Python class which has two methods get_String and print_String. 
# get_String accept a string from the user and print_String print the string in upper 
# case. 

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