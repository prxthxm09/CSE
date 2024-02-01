# 2. Write a Python class to find a pair of elements (indices of the two numbers) 
# from 
# a given array whose sum equals a specific target number. 
# Input: numbers= [10,20,10,40,50,60,70], target=50 
# Output: 3, 4 

class Twosum:
	def find(self, arr, targ):
		d = {}
		for i in range(len(arr)):
			c = targ-arr[i]
			if c in d:
				print(d[c], i)
				break
			d[arr[i]] = i
		else:
			print("Not Possible")

ts = Twosum()
print("Enter array: ")
arr = list(map(int, input().split()))
targ = int(input("Enter target: "))
ts.find(arr, targ)
	
