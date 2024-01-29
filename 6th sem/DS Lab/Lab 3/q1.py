#1. Write a program to find the factors of a given number (get input from user) using for loop.
import numpy as np

x = int(input("Enter the number : "))
A = np.array([1])
for i in range(2, x+1):
    if x%i == 0:
        A = np.append(A, i)
print(A)
