# 3. Write a python program to implement binary search with recursion.

def recur(l, r) -> int:
	if l>r:
		return -1
	m = (l+r+1)//2
	if arr[m]==targ:
		return m
	if arr[m]<targ:
		return recur(m+1, r)
	else:
		return recur(l,m-1)
7

print("Enter list: ")
arr = list(map(int, input().split()))
arr.sort()
targ = int(input("Enter target: "))
t = recur(0, len(arr)-1)
if t==-1:
	print("Not Found\n")
else:
	print("Found at", t-1, "\n")