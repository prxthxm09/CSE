import random
for i in range(100):
	n=random.randint(0,101)
	if n%2==0:
		print("%s\t%s"%("Even",1))
	else:
		print("%s\t%s"%("Odd",1))