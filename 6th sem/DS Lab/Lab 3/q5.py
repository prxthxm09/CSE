#5. Write a program to add two matrices.
import numpy as np

F = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
D = F.T
print(F,D)
print("Sum:", F+D)
