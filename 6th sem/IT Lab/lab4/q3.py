# 3. Write a Python class to implement pow(x, n).

# https://www.geeksforgeeks.org/fast-exponentiation-in-python/

class Powerfunc:
	# Approach 1:
	def pow(self, x, n):
		if n==0:
			return 1
		p = 1
		for _ in range(abs(n)):
			p *=x
		return p if n>0 else 1/p

if __name__=='__main__':
	print("Enter x and n for pow(x, n): ")
	x = int(input())
	n = int(input())
	print(Powerfunc().pow(x,n))