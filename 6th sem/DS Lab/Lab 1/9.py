numbers = [11, -21, 0, 45, 66, -93]

positive_count = 0
negative_count = 0

for num in numbers:
    if num > 0:
        positive_count += 1
    elif num < 0:
        negative_count += 1

print("Number of positive numbers:", positive_count)
print("Number of negative numbers:", negative_count)
