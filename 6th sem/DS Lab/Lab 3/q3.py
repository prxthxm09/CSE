import numpy as np

print("Enter array1 in one line: ")
x = [float(i) for i in input().split()]
A = np.array(x)
print(A)

print("Enter array2 in one line: ")
t = tuple([int(i) for i in input().split()])
B = np.array(t)
print(B)

#All zeroes
C = np.zeros((3, 4))
print(C)

#First parameter is no of planes: no of matrix to be split into, here 2.
D = np.reshape(C, (2, 2, 3))
print(D)

#matrix with elements from 0 to 20 with step value of 5.
E = np.arange(0, 20, 5)
print(E)

#min of col,row and max of col,row and sum of col,row.
F = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(np.min(F, axis=1), np.min(F, 0), np.max(F, 1), np.max(F, 0), np.sum(F, 1), np.sum(F, 0))