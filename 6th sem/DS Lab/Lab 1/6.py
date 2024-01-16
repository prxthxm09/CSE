my_tuple = (1, 3, 5, 7, 9, 2, 4, 6, 8, 10)
midpoint = len(my_tuple) // 2
for i in range(midpoint):
    print(my_tuple[i], end=" ")
print()
for i in range(midpoint, len(my_tuple)):
    print(my_tuple[i], end=" ")
