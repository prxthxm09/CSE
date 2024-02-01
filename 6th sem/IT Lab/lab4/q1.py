
class Powerset:
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
	ps = Powerset()
	print(ps.find(arr))
