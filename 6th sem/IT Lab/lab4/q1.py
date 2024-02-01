# 1. Write a Python class to get all possible unique subsets from a set of distinct 
# integers Input:[4,5,6] 
# Output : [[], [6], [5], [5, 6], [4], [4, 6], [4, 5], [4, 5, 6]] 

class Powerset:
	# Approach 1:
	def find(self, arr):
		n = len(arr)
		ps_n = 2**n
		l = []
		for c in range(ps_n):
			l1 = []
			for j in range(n):
				if (c & (1<<j)):
					l1.append(arr[j])
			l.append(l1)
		return l

if __name__ == '__main__':
	arr = [ int(x) for x in input('Enter array: ').split() ]
	# enclosing this in () will create an object arr of type generator
	# and enclosing it in set() will create a set object which is not subscriptable
	ps = Powerset()
	print(ps.find(arr))
