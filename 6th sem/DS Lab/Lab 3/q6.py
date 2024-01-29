#6. Write a program to find element wise product between two matrices.
import numpy as np

F = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
D = F.T

#print(F.dot(D))
print(np.multiply(F,D))
