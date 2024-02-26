import fileinput
max_value = 0.0
for line in fileinput.input():
	data = line.strip().split("\t")
	if len(data) != 2:
	# Something has gone wrong. Skip this line.
		continue
	cur_loc, cur_cost = data
	# Refresh for new keys (i.e. locations in the example context)
	if float(cur_cost) > float(max_value):
		max_value = float(cur_cost)
print (max_value)