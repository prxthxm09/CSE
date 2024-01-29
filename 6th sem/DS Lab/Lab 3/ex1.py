import numpy as np
#Usage of for-loop (Mapping by Value)
#Calculate sum of all the elements in a 2D Numpy Array (iterate over elements)

a=np.array([(3,2,9),(1,6,7)])
s1=0
for row in a:
  for col in row:
    s1+=col
print(s1)

#Usage of for-loop (Mapping by Index)
#Calculate sum of all the elements in a 2D Numpy Array (iterate over range)

a=np.array([(3,2,9),(1,6,7)])
s=0
for i in range(a.shape[0]):
  for j in range(a.shape[1]):
    s+=a[i,j]
print(s)
